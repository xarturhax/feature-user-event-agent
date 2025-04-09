#include <sc-memory/sc_keynodes.hpp>

class UserEventsKeynodes : public ScKeynodes
{
public:
  static inline ScKeynode const action_user_events{
    "action_user_events", ScType::ConstNodeClass};
  static inline ScKeynode const nrel_user_event{
    "nrel_user_event", ScType::ConstNodeNonRole};
  static inline ScKeynode const concept_user{
    "concept_user", ScType::ConstNodeClass};
  static inline ScKeynode const nrel_main_idtf{
    "nrel_main_idtf", ScType::ConstNodeNonRole};
  static inline ScKeynode const rrel_key_sc_element{
    "rrel_key_sc_element", ScType::ConstNodeRole};
  static inline ScKeynode const rrel_example{
    "rrel_example", ScType::ConstNodeRole};
  static inline ScKeynode const nrel_sc_text_translation{
    "nrel_sc_text_translation", ScType::ConstNodeNonRole};
  static inline ScKeynode const lang_ru{
    "lang_ru", ScType::ConstNodeClass};
  static inline ScKeynode const lang_by{
    "lang_by", ScType::ConstNodeClass};
  static inline ScKeynode const lang_en{
    "lang_en", ScType::ConstNodeClass};
  static inline ScKeynode const empty_set{
    "empty_set", ScType::ConstNodeClass};
};