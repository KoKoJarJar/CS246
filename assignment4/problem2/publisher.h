#ifndef __PUBLISHER__
#define __PUBLISHER__

#include "state.h"

class Publisher {
public:
  virtual void publish(State &prev_state, State &curr_state) = 0;
  ~Publisher(){};
};

#endif
