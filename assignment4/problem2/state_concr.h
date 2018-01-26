#include "state.h"

class State_concr {
  unsigned int color;
  public:
  State_concr(unsigned int input = 0);
  unsigned int get_value();
  unsigned int set_value(unsigned int input);
};
