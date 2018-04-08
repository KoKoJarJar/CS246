#ifndef __PRINTER__
#define __PRINTER__

#include "game.h"
#include <ostream>

// class Printer has the responsibility to print a game to the output
class Printer {
public:
  // print(game, out) prints the game to out
  // side effects: I/O
  virtual void print(const Game &game, std::ostream &out) = 0;

  // Destructor
  ~Printer(){};
};

#endif
