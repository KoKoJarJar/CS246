#ifndef __BUILDER__
#define __BUILDER__

#include "cell.h"
#include "game.h"
#include "grid.h"
#include "input.h"
#include "printer.h"
#include "propagator.h"

// Class builder injects all requirements to classes
// memory has to be freed by the caller
class Builder {
public:
  // build_cell(value) builds a cell with state value
  virtual Cell *build_cell(unsigned int value) const = 0;

  // build_grid(size, max_state) builds a grid with size and max_state
  virtual Grid *build_grid(unsigned int size, unsigned int max_state) const = 0;

  // build_propagator() builds a propagator
  virtual Propagator *build_propagator() const = 0;

  // build_game(size, max_state) builds a game with size and max_state
  virtual Game *build_game(unsigned int size, unsigned int max_state) const = 0;

  // build_printer() builds a printer
  virtual Printer *build_printer() const = 0;

  // build_input() builds an input
  virtual Input *build_input() const = 0;

  ~Builder(){};
};

#endif
