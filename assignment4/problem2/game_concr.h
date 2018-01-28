#ifndef __GAME_CONCR__
#define __GAME_CONCR__

#include "cell.h"
#include "printer.h"
#include "game.h"
#include <memory>
#include <vector>

class Game_concr : public Game {
  std::unique_ptr<std::vector<Cell *>> grid;
  Printer &printer;
  unsigned int moves;
  unsigned int number;

public:
  Game_concr(std::vector<Cell *> &grid, Printer &printer, const unsigned int difficulty = 25, const unsigned int number = 5);
  std::vector<Cell *> &get_cell();
  void set(State &state);
  bool finished();
  bool won();
  unsigned int moves_left();
  unsigned int size();
};

#endif
