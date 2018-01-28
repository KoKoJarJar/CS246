#include "game_concr.h"
#include <memory>
#include <vector>

Game_concr::Game_concr(std::vector<Cell *> &grid, Printer &printer, const unsigned int difficulty,
                       const unsigned int number)
    : grid(&grid), printer(printer), moves(difficulty), number(number) {
}

std::vector<Cell *> &Game_concr::get_cell() {
  return *(grid.get());
}

void Game_concr::set(State &state) {
  grid.get()->at(0)->update(state);
  printer.print();
  --moves;
}

bool Game_concr::finished() {
  return moves_left() == 0;
}

bool Game_concr::won() {
  std::vector<Cell *> &temp = *(grid.get());
  Cell &temp_state = *(temp.at(0));
  for (auto &&v : temp) {
    if (temp_state != *v) {
      return false;
    }
  }
  return true;
}

unsigned int Game_concr::moves_left() {
  return moves;
}

unsigned int Game_concr::size() {
  return number;
}
