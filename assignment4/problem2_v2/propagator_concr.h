#ifndef __PROPAGATOR_CONCR__
#define __PROPAGATOR_CONCR__

#include "grid.h"
#include "propagator.h"
#include <ostream>
#include <set>
#include <vector>

struct Posn {
  unsigned int x;
  unsigned int y;
  Posn(unsigned int x = 0, unsigned int y = 0);
};

class Propagator_concr : public Propagator {
  std::set<Posn> visited_set;
  void propagate_helper(Grid &grid, unsigned int i, unsigned int j, unsigned int value);
  inline std::vector<Posn> neighbours(unsigned int i, unsigned int j, unsigned int value) const;

public:
  Propagator_concr();
  void propagate(Grid &grid, unsigned int i, unsigned int j, unsigned int value);
};

bool operator<(const Posn &posn0, const Posn &posn1);
#endif
