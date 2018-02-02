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
  unsigned int index(unsigned int i, unsigned int j) const;

public:
  Grid_concr(unsigned int size, unsigned int max_state, const std::vector<Cell *> &grid);
  Grid_concr(const Grid_concr &grid) = delete;
  Grid_concr &operator=(const Grid_concr &grid) = delete;
  bool update(unsigned int i, unsigned int j, unsigned int value);
  const Cell &get_cell(unsigned int i, unsigned int j) const;
  unsigned int get_size() const;
  unsigned int get_max_state() const;
  bool is_equal() const;
};

#endif
