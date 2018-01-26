#include "cell.h"
#include "printer.h"
#include <memory>
#include <vector>

class Game_concr {
  std::unique_ptr<vector<Cell>> grid;
  Printer &printer;
  unsigned int moves;
  unsigned int size;

public:
  Game_concr(vector<Cell> &grid, Printer &printerm);
  std::vector<Cell> &get_cell();
  void set(State &state);
  bool finished();
  bool won();
  unsigned int moves_left();
  unsigned int size();
};
