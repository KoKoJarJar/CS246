#ifndef __CELL__
#define __CELL__

#include <ostream>

// class Cell, which has the responsibility to wrap a state, update and
// be compared with other Cells
// class Cell is used as a primary component for class Grid
class Cell {
public:
  // get_state() returns the state of Cell
  virtual unsigned int get_state() const = 0;

  // update(state) updates the state of Cell
  // side effects: changes the state of Cell
  virtual bool update(unsigned int state) = 0;

  // ==(cell) returns the equality compared with another cell
  virtual bool operator==(const Cell &cell) const = 0;

  // !=(cell) returns the negation of ==(cell)
  virtual bool operator!=(const Cell &cell) const = 0;

  // <<(out, cell) returns the output stream and
  // side effect: prints cell to out
  friend std::ostream &operator<<(std::ostream &out, const Cell &cell);

  // virtual destructor
  virtual ~Cell(){};
};

// <<(out, cell) returns the output stream and
// side effect: prints cell to out
std::ostream &operator<<(std::ostream &out, const Cell &cell);

#endif
