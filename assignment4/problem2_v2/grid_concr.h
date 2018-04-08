#ifndef __GRID_CONCR__
#define __GRID_CONCR__

#include "cell.h"
#include "grid.h"
#include <memory>
#include <vector>

class Grid_concr : public Grid {
  unsigned int size;
  unsigned int max_state;
  std::vector<std::unique_ptr<Cell>> grid;

  // index(i, j) returns the sequential index of the grid
  // based on 2d indexing (i,j)
  unsigned int index(unsigned int i, unsigned int j) const;

public:
  // Constructor
  Grid_concr(unsigned int size, unsigned int max_state, const std::vector<Cell *> &grid);

  // Cannot be copied
  Grid_concr(const Grid_concr &grid) = delete;

  // Cannot be copied
  Grid_concr &operator=(const Grid_concr &grid) = delete;

  // See grid.h for description
  bool update(unsigned int i, unsigned int j, unsigned int value);
  
  // See grid.h for description
  const Cell &get_cell(unsigned int i, unsigned int j) const;

  // See grid.h for description
  unsigned int get_size() const;

  // See grid.h for description
  unsigned int get_max_state() const;

  // See grid.h for description
  bool is_equal() const;
};

#endif
