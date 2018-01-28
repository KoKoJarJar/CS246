#ifndef __CELL_CONCR__
#define __CELL_CONCR__

#include "cell.h"
#include "state.h"
#include <memory>

class Cell_concr : public Cell {
  std::unique_ptr<Publisher> publisher;
  std::unique_ptr<State> state;
  void notify(State &prev_state, State &curr_state);

public:
  Cell_concr(State &state);
  State &get_state();
  void update(State &state);
  void add_publisher(Publisher &publisher);
  bool operator==(Cell &cell);
  bool operator!=(Cell &cell);
};

#endif
