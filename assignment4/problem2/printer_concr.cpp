#include "cell.h"
#include "printer_conr.h"
#include <iostream>
#include <string>
#include <vector>

Printer_concr::Printer_concr(Game &game) : game(game){};

void Printer_concr::print() {
  std::vector<Cell> &temp = game.get_cell();
  unsigned int size = game.size();
  for (unsigned int j = 0; j < size; ++j) {
    for (unsigned int i = 0; i < size; ++i) {
      std::cout << temp.at(i).state().get_state() << " ";
    }
    std::cout << std::endl;
  }
}
