#ifndef __PROPAGATOR__
#define __PROPAGATOR__

#include "grid.h"
#include <ostream>

class Propagator {
public:
  virtual void propagate(Grid &grid, unsigned int i, unsigned int j, unsigned int value) = 0;
  virtual ~Propagator(){};
};

#endif
