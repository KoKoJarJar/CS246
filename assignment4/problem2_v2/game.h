#ifndef __GAME__
#define __GAME__

#include "grid.h"
#include <ostream>

class Game {
public:
  virtual const Grid &get_grid() const = 0;
  virtual void update(unsigned int value) = 0;
  virtual bool won() const = 0;
  virtual bool finished() const = 0;
  virtual unsigned int moves_left() const = 0;
  virtual unsigned int size() const = 0;
  friend std::ostream &operator<<(std::ostream &out, Game &game);
  ~Game(){};
};

std::ostream &operator<<(std::ostream &out, const Game &game);

#endif
