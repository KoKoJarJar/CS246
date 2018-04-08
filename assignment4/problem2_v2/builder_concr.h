#ifndef __BUILDER_CONCR__
#define __BUILDER_CONCR__

#include "builder.h"
#include "cell.h"
#include "game.h"
#include "grid.h"
#include "printer.h"
#include "propagator.h"

// see builder.h for description
class Builder_concr : public Builder {
public:
  // Constructor
  Builder_concr();
  Cell *build_cell(unsigned int value) const;
  Grid *build_grid(unsigned int size, unsigned int max_state) const;
  Propagator *build_propagator() const;
  Game *build_game(unsigned int size, unsigned int max_state) const;
  Printer *build_printer() const;
  Input *build_input() const;
};

#endif
