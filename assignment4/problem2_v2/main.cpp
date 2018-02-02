#include "builder.h"
#include "builder_concr.h"
#include "game.h"
#include "input.h"
#include "printer.h"
#include <iostream>

int main() {
  std::ostream &out = std::cout;
  std::istream &in = std::cin;
  Builder_concr builder;
  Game &game = *(builder.build_game(5, 5));
  Printer &printer = *(builder.build_printer());
  Input &input = *(builder.build_input());
  while (true) {
    if (game.won() || game.finished()) {
      break;
    }
    game.update(input.read_value(in));
    printer.print(game, out);
  }
}
