#ifndef __CELL__
#define __CELL__

#include "publisher.h"
#include "state.h"
#include <ostream>

class Cell {
public:
  virtual void update(State &state) = 0;
  virtual State &get_state() = 0;
  virtual void add_publisher(Publisher &publisher) = 0;
  virtual bool operator==(Cell &cell) = 0;
  virtual bool operator!=(Cell &cell) = 0;
  friend std::ostream &operator<<(std::ostream &out, Cell &cell);
  virtual ~Cell(){};
};

std::ostream &operator<<(std::ostream &out, Cell &cell);

#endif
