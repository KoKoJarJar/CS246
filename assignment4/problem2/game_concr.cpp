#include "game_concr.h"
#include <memory>
#include <vector>

Game_concr::Game_concr(vector<Cell> &grid, const unsigned int difficulty = 25)
    : grid(grid), moves(25){};

std::vector<Cell> &Game_concr::get_cell() {
  return grid.get();
}

void Game_concr::set(State &state) {
  grid.at(0).update(state);
  printer.print();
}

bool Game_concr::finished() {
  return moves_left() == 0;
}

bool Game_concr::won() {
  State temp_state = grid.at(0).state();
  for (auto v : grid) {
    if (temp_state.get_state() != v.state().get_state()) {
      return false;
    }
  }
  return true;
}

unsigned int Game_concr::moves_left() {
  return moves;
}

unsigned int size() {
  return size;
}
