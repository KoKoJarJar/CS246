#include "cell.h"
#include "grid.h"
#include <ostream>

std::ostream &operator<<(std::ostream &out, const Grid &grid) {
  for (unsigned int i = 0; i < grid.get_size(); ++i) {
    for (unsigned int j = 0; j < grid.get_size(); ++j) {
      if (j != grid.get_size() - 1) {
        out << grid.get_cell(i, j) << " ";
      }
    }
    out << std::endl;
  }
  return out;
}
