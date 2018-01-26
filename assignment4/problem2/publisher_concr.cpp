#include "publisher_concr.h"
#include <cell>
#include <memory>
#include <vector>

Publisher_concr::Publisher_concr(const Cell &prim_cell, const vector<&Cell> neighbours)
    : prim_cell(prim_cell), neighbours(neighbours){};

void Publisher_concr::publish(State &prev_state, State &curr_state) {
  vector<*Cell> temp_vec = neighbours_get();
  for (auto v : temp_vec) {
    if (v->state().get_state() == prev_state.get_state()) {
      v->update(curr_state);
    }
  }
}
