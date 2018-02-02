#include "game.h"
#include <ostream>

std::ostream &operator<<(std::ostream &out, const Game &game) {
  return out << game.get_grid();
}

