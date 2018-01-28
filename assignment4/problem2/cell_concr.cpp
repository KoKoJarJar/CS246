#include "cell_concr.h"
#include "state.h"
#include "state_concr.h"
#include <iostream>
#include <memory>

Cell_concr::Cell_concr(State &state) : state(&state) {
}

State &Cell_concr::get_state() {
  return *state.get();
}

void Cell_concr::update(State &state) {
  std::unique_ptr<State> prev_state = std::move(this->state);
  this->state.reset(new State_concr(state.get_value()));
  notify(*prev_state.get(), state);
}

void Cell_concr::notify(State &prev_state, State &curr_state) {
  if (!publisher) {
    return;
  }
  publisher.get()->publish(prev_state, curr_state);
}

void Cell_concr::add_publisher(Publisher &publisher) {
  this->publisher.reset(&publisher);
}

bool Cell_concr::operator==(Cell &cell) {
  return *state.get() == cell.get_state();
}

bool Cell_concr::operator!=(Cell &cell) {
  return *state.get() != cell.get_state();
}
