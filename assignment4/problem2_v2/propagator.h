#ifndef __PROPAGATOR__
#define __PROPAGATOR__

#include "grid.h"
#include <ostream>

// class Propagator, has the responsibility to propagate a state in a grid
class Propagator {
public:
  // propagate(grid, i, j, value) propagates the state value in the grid at the (i,j) position
  virtual void propagate(Grid &grid, unsigned int i, unsigned int j, unsigned int value) = 0;

  // Destructor
  virtual ~Propagator(){};
};

#endif
