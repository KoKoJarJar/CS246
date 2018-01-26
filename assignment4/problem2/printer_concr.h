#include "game.h"
#include "printer.h"
#include <vector>

class Printer_concr {
  Game &game;

public:
  Printer_concr(Game &game);
  void print();
};
