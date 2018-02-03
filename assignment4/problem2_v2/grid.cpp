#include "cell.h"
#include "grid.h"
#include <ostream>

std::ostream &operator<<(std::ostream &out, const Grid &grid) {
  for (unsigned int i = 0; i < grid.get_size(); ++i) {
    for (unsigned int j = 0; j < grid.get_size(); ++j) {
      out << grid.get_cell(i, j);
      if (j != grid.get_size() - 1) {
        out << " ";
      }
    }
    out << std::endl;
  }
  return out;
}
