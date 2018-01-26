#include "cell.h"
#include "publisher.h"
#include <memory>
#include <vector>

class Publisher_concr {
  Cell &prim_cell;
  std::unique_ptr<vector<*Cell>> neighbours;

public:
  Publisher_concr(const Cell &prim_cell, const vector<*Cell> neighbours);
  void publish(State &prev_state, State &curr_state);
};
