#ifndef __BUILDER__
#define __BUILDER__

#include "cell.h"
#include "game.h"
#include "grid.h"
#include "input.h"
#include "printer.h"
#include "propagator.h"

class Builder {
public:
  virtual Cell *build_cell(unsigned int value) const = 0;
  virtual Grid *build_grid(unsigned int size, unsigned int max_state) const = 0;
  virtual Propagator *build_propagator() const = 0;
  virtual Game *build_game(unsigned int size, unsigned int max_state) const = 0;
  virtual Printer *build_printer() const = 0;
  virtual Input *build_input() const = 0;
  ~Builder(){};
};

#endif
