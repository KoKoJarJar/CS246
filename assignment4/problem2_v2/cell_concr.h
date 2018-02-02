#ifndef __CELL_CONCR__
#define __CELL_CONCR__

#include "cell.h"

class Cell_concr : public Cell {
  unsigned int state;

public:
  Cell_concr();
  Cell_concr(unsigned int state);
  unsigned int get_state() const;
  bool update(unsigned int state);
  bool operator==(const Cell &cell) const;
  bool operator!=(const Cell &cell) const;
};

#endif
