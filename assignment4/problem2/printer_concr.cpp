#include "cell.h"
#include "printer_concr.h"
#include <iostream>
#include <string>
#include <vector>

void Printer_concr::print() {
  std::vector<Cell *> &temp = game->get_cell();
  unsigned int size = game->size();
  for (unsigned int j = 0; j < size; ++j) {
    for (unsigned int i = 0; i < size; ++i) {
      std::cout << *(temp.at(i * size + j)) << " ";
    }
    std::cout << std::endl;
  }
}

void Printer_concr::add_game(Game &game) {
  this->game = &game;
}
