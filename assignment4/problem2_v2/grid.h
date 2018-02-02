#ifndef __GRID__
#define __GRID__

#include "cell.h"
#include <ostream>

class Grid {
public:
  virtual bool update(unsigned int i, unsigned int j, unsigned int value) = 0;
  virtual const Cell &get_cell(unsigned int i, unsigned int j) const = 0;
  virtual unsigned int get_size() const = 0;
  virtual unsigned int get_max_state() const = 0;
  virtual bool is_equal() const = 0;
  friend std::ostream &operator<<(std::ostream &out, const Grid &grid);
  virtual ~Grid(){};
};

std::ostream &operator<<(std::ostream &out, const Grid &grid);

#endif
