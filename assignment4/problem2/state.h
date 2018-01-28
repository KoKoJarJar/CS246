#ifndef __STATE__
#define __STATE__

#include <ostream>

class State {
public:
  virtual unsigned int get_value() = 0;
  virtual void set_value(unsigned int input) = 0;
  virtual bool operator==(State &state) = 0;
  virtual bool operator!=(State &state) = 0;
  friend std::ostream &operator<<(std::ostream &out, State &state);
  virtual ~State(){};
};

std::ostream &operator<<(std::ostream &out, State &state);

#endif
