#ifndef __PRINTER_CONCR__
#define __PRINTER_CONCR__

#include "game.h"
#include "printer.h"

class Printer_concr : public Printer {
  Game *game;

public:
  void add_game(Game &game);
  void print();
};

#endif
