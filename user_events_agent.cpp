#include "user_events_agent.hpp"
#include <iostream>
#include <sc-memory/sc_memory_headers.hpp>
#include "keynodes/user_events_keynodes.hpp"


ScAddr ScUserEventsAgent::GetActionClass() const
{
    return UserEventsKeynodes::action_user_events;
}

ScResult ScUserEventsAgent::DoProgram(ScAction & action)
{
    auto const & [userAddr] = action.GetArguments<1>(); 
    ScStructure resultStruct = m_context.GenerateStructure();

    if (!m_context.IsElement(userAddr)) 
    {
        SC_LOG_ERROR("Invalid ScAddr provided.");
        return action.FinishUnsuccessfully();
    }

    if (!m_context.HelperCheckEdge(UserEventsKeynodes::concept_user, userAddr, ScType::ConstPermPosArc))
    {
        SC_LOG_ERROR("Provided address is not recognized as a user.");
        return action.FinishUnsuccessfully();
    }

    SC_LOG_INFO("Searching for events linked to the user...");
    
    ScTemplate eventTemplate;
    eventTemplate.Quintuple(
        userAddr,
        ScType::VarCommonArc >> "_edge",
        ScType::VarNode >> "_event",
        ScType::VarPermPosArc,
        UserEventsKeynodes::nrel_user_event
    );

    ScTemplateSearchResult searchResult;
    m_context.SearchByTemplate(eventTemplate, searchResult);

    if (searchResult.IsEmpty()) 
    {
        SC_LOG_INFO("No events found for the user.");
        action.SetResult(resultStruct);
        return action.FinishSuccessfully();
    }

    for (size_t i = 0; i < searchResult.Size(); ++i)
    {
        ScTemplateResultItem resultItem;
        searchResult.Get(i, resultItem);
        
        ScAddr eventAddr;
        resultItem.Get("_event", eventAddr);
        
        if (m_context.IsElement(eventAddr)) 
        {
            resultStruct << eventAddr;
            SC_LOG_INFO("Found event: " + m_context.GetElementSystemIdentifier(eventAddr));
        }
    }

    SC_LOG_INFO("Total events found: " + std::to_string(searchResult.Size()));

    action.SetResult(resultStruct);
    return action.FinishSuccessfully();
}