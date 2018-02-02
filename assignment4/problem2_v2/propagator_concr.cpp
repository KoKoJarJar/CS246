#include "cell.h"
#include "grid.h"
#include "propagator_concr.h"
#include <iostream>

Posn::Posn(unsigned int x, unsigned int y) : x(x), y(y) {
}

bool operator<(const Posn &posn0, const Posn &posn1) {
  if (posn0.x < posn1.x) {
    return true;
  }
  if (posn0.x == posn1.x && posn0.y < posn1.y) {
    return true;
  }
  return false;
}

Propagator_concr::Propagator_concr() {
}

void Propagator_concr::propagate(Grid &grid, unsigned int i, unsigned int j, unsigned int value) {
  visited_set.clear();
  propagate_helper(grid, i, j, value);
}

void Propagator_concr::propagate_helper(Grid &grid, unsigned int i, unsigned int j,
                                        unsigned int value) {
  if (visited_set.count(Posn(i, j)) == 0) {
    visited_set.insert(Posn(i, j));
    std::vector<Posn> neighbs = neighbours(i, j, grid.get_size());
    for (auto v : neighbs) {
      if (grid.get_cell(v.x, v.y) == grid.get_cell(i, j)) {
        propagate_helper(grid, v.x, v.y, value);
      }
    }
    if (!grid.update(i, j, value)) {
      throw "error";
    }
  }
}

inline std::vector<Posn> Propagator_concr::neighbours(unsigned int i, unsigned int j,
                                                      unsigned int size) const {
  std::vector<Posn> return_val;
  for (auto offset : {-1, 1}) {
    if (static_cast<int>(offset + i) >= 0 && (offset + i) < size) {
      return_val.push_back(Posn(offset + i, j));
    }
  }
  for (auto offset : {-1, 1}) {
    if (static_cast<int>(offset + j) >= 0 && (offset + j) < size) {
      return_val.push_back(Posn(i, offset + j));
    }
  }
  return return_val;
}
