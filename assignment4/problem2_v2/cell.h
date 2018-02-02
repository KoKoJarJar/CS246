#ifndef __CELL__
#define __CELL__

#include <ostream>

class Cell {
public:
  virtual unsigned int get_state() const = 0;
  virtual bool update(unsigned int state) = 0;
  virtual bool operator==(const Cell &cell) const = 0;
  virtual bool operator!=(const Cell &cell) const = 0;
  friend std::ostream &operator<<(std::ostream &out, Cell &cell);
  virtual ~Cell(){};
};

std::ostream &operator<<(std::ostream &out, const Cell &cell);

#endif
