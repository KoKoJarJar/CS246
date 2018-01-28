#ifndef __PRINTER__
#define __PRINTER__

#include "game.h"

class Printer {
public:
  virtual void print() = 0;
  virtual void add_game(Game &game) = 0;
  ~Printer(){};
};

#endif
