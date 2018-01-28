#ifndef __PUBLISHER_CONCR__
#define __PUBLISHER_CONCR__

#include "cell.h"
#include "publisher.h"
#include <memory>
#include <vector>

class Publisher_concr : public Publisher {
  Cell &prim_cell;
  std::unique_ptr<std::vector<Cell *>> neighbours;

public:
  Publisher_concr(Cell &prim_cell, std::vector<Cell *> &neighbours);
  void publish(State &prev_state, State &curr_state);
};

#endif
