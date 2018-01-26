#include "cell_concr.h"
#include <memory>

Cell_concr::Cell_concr(State &state) : state(state){};

Cell_concr::State state() {
  return state;
}

void Cell_concr::update(State state) {
  State prev_state = state;
  this->state = state;
  notify(prev_state, state);
}

void Cell_concr::notify(State prev_state, State curr_state) {
  if (!publisher) {
    return;
  }
  publisher.get()->publish(prev_state, curr_state);
}

void Cell_concr::add_publisher(const Publisher &publisher) {
  this->publisher.reset(publisher);
}
