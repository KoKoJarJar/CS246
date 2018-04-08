#ifndef __PROPAGATOR_CONCR__
#define __PROPAGATOR_CONCR__

#include "grid.h"
#include "propagator.h"
#include <ostream>
#include <set>
#include <vector>

// Position structure
struct Posn {
  unsigned int x;
  unsigned int y;
  Posn(unsigned int x = 0, unsigned int y = 0);
};

class Propagator_concr : public Propagator {
  // Set to see which positions have been visited, to avoid
  // visiting them again durring recursion
  std::set<Posn> visited_set;

  // helper for propagate main recursion takes place here
  // side effects: modifies the grid
  void propagate_helper(Grid &grid, unsigned int i, unsigned int j, unsigned int value);

  // neighbours(i, j, value) returns a vector of positions that are neighbours of position
  // (i,j), with size as the size of the grid
  inline std::vector<Posn> neighbours(unsigned int i, unsigned int j, unsigned int size) const;

public:
  // constructor
  Propagator_concr();

  // see header for description
  void propagate(Grid &grid, unsigned int i, unsigned int j, unsigned int value);
};

// compares two positions based on total ordering x then y
bool operator<(const Posn &posn0, const Posn &posn1);
#endif
