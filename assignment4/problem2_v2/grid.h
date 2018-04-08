#ifndef __GRID__
#define __GRID__

#include "cell.h"
#include <ostream>

// class Grid is composed of a 2d grid composed of Cells
// class grid has the responsibility to update, and obtain general
// information about itself
class Grid {
public:
  // update(i, j, value) updates the (i,j) cell with state value
  // side effects: changes the state of cell at (i,j)
  virtual bool update(unsigned int i, unsigned int j, unsigned int value) = 0;

  // get_cell(i, j) returns the cell at the (i,j) cell
  // the returned cell cannot be mutated
  virtual const Cell &get_cell(unsigned int i, unsigned int j) const = 0;

  // get_size() returns the size of the grid (number of rows or columns)
  virtual unsigned int get_size() const = 0;

  // get_max_state() returns the max_state of the all the cells in the grid
  virtual unsigned int get_max_state() const = 0;

  // is_equal() if all the states in the grid are the same, returns true,
  // otherwise returns false
  virtual bool is_equal() const = 0;

  // <<(out, grid) outputs grid to out and returns the output stream out
  // side effects: I/O
  friend std::ostream &operator<<(std::ostream &out, const Grid &grid);

  // Destructor
  virtual ~Grid(){};
};

// <<(out, grid) outputs grid to out and returns the output stream out
// side effects: I/O
std::ostream &operator<<(std::ostream &out, const Grid &grid);

#endif
