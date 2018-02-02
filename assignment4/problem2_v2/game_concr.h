#ifndef __GAME_CONCR__
#define __GAME_CONCR__

#include "cell.h"
#include "game.h"
#include "propagator.h"
#include <memory>

class Game_concr : public Game {
  std::unique_ptr<Grid> grid;
  std::unique_ptr<Propagator> propagator;
  unsigned int moves_left_prv = 25;

public:
  Game_concr(Grid *grid, Propagator *propagator);
  Game_concr(const Game_concr &game_concr) = delete;
  Game_concr &operator=(const Game_concr &game_concr) = delete;
  const Grid &get_grid() const;
  void update(unsigned int value);
  bool won() const;
  bool finished() const;
  unsigned int moves_left() const;
  unsigned int size() const;
};

#endif
