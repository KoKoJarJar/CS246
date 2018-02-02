#ifndef __PRINTER__
#define __PRINTER__

#include "game.h"
#include <ostream>

class Printer {
public:
  virtual void print(const Game &game, std::ostream &out) = 0;
  ~Printer(){};
};

#endif
