#include "game.h"
#include "printer_concr.h"
#include <ostream>

Printer_concr::Printer_concr() {
}

void Printer_concr::print(const Game &game, std::ostream &out) {
  out << game;
}
