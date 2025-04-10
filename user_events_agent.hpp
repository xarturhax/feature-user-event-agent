#pragma once

#include <sc-memory/sc_agent.hpp>

class ScUserEventsAgent : public ScActionInitiatedAgent
{
public:
    ScAddr GetActionClass() const override;

    ScResult DoProgram(ScAction & action) override;
};