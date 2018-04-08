#ifndef __GAME__
#define __GAME__

#include "grid.h"
#include <ostream>

// class Game is composed of a grid and has the responsibility to
// manage the model of the game
class Game {
public:
  // get_grid() returns the grid
  // notes: cannot be mutated
  virtual const Grid &get_grid() const = 0;

  // update(value) updates the (0,0) cell with state value
  // side effects: updates the game
  virtual void update(unsigned int value) = 0;

  // won() returns true if the game has been won
  virtual bool won() const = 0;

  // finished() returns true if the game is finished
  virtual bool finished() const = 0;

  // moves_left() returns the number of moves left
  virtual unsigned int moves_left() const = 0;

  // size() returns the size of the game (number of rows or columns)
  virtual unsigned int size() const = 0;

  // <<(out, game) returns the output stream and prints the game to out
  // side effects: I/O
  friend std::ostream &operator<<(std::ostream &out, Game &game);

  ~Game(){};
};

// <<(out, game) returns the output stream and prints the game to out
// side effects: I/O
std::ostream &operator<<(std::ostream &out, const Game &game);

#endif
