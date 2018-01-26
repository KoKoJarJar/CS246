#include "cell.h"
#include <memory>

class Cell_concr {
  std::unique_ptr<Publisher> publisher;
  State state;
  void notify(State prev_state, State curr_state);

public:
  Cell_concr(State state);
  State get_state();
  void update(State state);
  void add_publisher(const Publisher &publisher);
};
