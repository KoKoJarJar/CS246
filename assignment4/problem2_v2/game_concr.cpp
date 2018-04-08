#include "game_concr.h"
#include "grid.h"

Game_concr::Game_concr(Grid *grid, Propagator *propagator, unsigned int moves_left)
    : grid(grid), propagator(propagator), moves_left_prv(moves_left) {
  if (grid == nullptr || propagator == nullptr || moves_left <= 0) {
    throw "error";
  }
}

void Game_concr::update(unsigned int value) {
  propagator.get()->propagate(*(grid.get()), 0, 0, value);
  --moves_left_prv;
}

bool Game_concr::won() const {
  return grid.get()->is_equal();
}

bool Game_concr::finished() const {
  return moves_left_prv == 0;
}

unsigned int Game_concr::moves_left() const {
  return moves_left_prv;
}

unsigned int Game_concr::size() const {
  return grid.get()->get_size();
}

const Grid &Game_concr::get_grid() const {
  return *(grid.get());
}
