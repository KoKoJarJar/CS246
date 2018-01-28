#include "state.h"

class State_concr : public State {
  unsigned int color;
  public:
  State_concr(unsigned int input = 0);
  unsigned int get_value();
  void set_value(unsigned int input);
  bool operator==(State &state);
  bool operator!=(State &state);
};
