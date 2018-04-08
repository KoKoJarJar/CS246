#ifndef __GAME_CONCR__
#define __GAME_CONCR__

#include "cell.h"
#include "game.h"
#include "propagator.h"
#include <memory>

class Game_concr : public Game {
  std::unique_ptr<Grid> grid;
  std::unique_ptr<Propagator> propagator;
  unsigned int moves_left_prv;

public:
  // Constructor
  Game_concr(Grid *grid, Propagator *propagator, unsigned int moves_left = 25);

  // Cannot copy the game
  Game_concr(const Game_concr &game_concr) = delete;

  // Cannot assign the game
  Game_concr &operator=(const Game_concr &game_concr) = delete;

  // See game.h for description
  const Grid &get_grid() const;

  // See game.h for description
  void update(unsigned int value);

  // See game.h for description
  bool won() const;

  // See game.h for description
  bool finished() const;

  // See game.h for description
  unsigned int moves_left() const;

  // See game.h for description
  unsigned int size() const;
};

#endif
