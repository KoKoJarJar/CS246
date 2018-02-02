#include "cell.h"
#include <ostream>

std::ostream &operator<<(std::ostream &out, const Cell &cell) {
  return out << cell.get_state();
}
