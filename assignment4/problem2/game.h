#include "cell.h"
#include "publisher.h"
#include <vector>

class Game {
public:
  virtual std::vector<Cell> &get_cell() = 0;
  virtual void set(State &state) = 0;
  virtual bool finished() = 0;
  virtual bool won() = 0;
  virtual unsigned int moves_left() = 0;
  virtual unsigned int size() = 0;
  virtual ~Game(){};
};
