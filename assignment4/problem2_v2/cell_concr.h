#ifndef __CELL_CONCR__
#define __CELL_CONCR__

#include "cell.h"

class Cell_concr : public Cell {
  // state of Cell_concr
  unsigned int state;

public:
  // Constructor
  Cell_concr();

  // Constructor
  Cell_concr(unsigned int state);

  // see Cell.h for description
  unsigned int get_state() const;

  // see Cell.h for description
  bool update(unsigned int state);

  // see Cell.h for description
  bool operator==(const Cell &cell) const;

  // see Cell.h for description
  bool operator!=(const Cell &cell) const;
};

#endif
