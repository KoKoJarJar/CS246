#include "cell.h"
#include "publisher_concr.h"
#include <memory>
#include <vector>
#include <iostream>

Publisher_concr::Publisher_concr(Cell &prim_cell, std::vector<Cell *> &neighbours)
    : prim_cell(prim_cell), neighbours(&neighbours) {
}

void Publisher_concr::publish(State &prev_state, State &curr_state) {
  std::vector<Cell *> &temp_vec = *(neighbours.get());
    std::cerr << "im here" << std::endl;
  for (auto &&v : temp_vec) {
    std::cerr << "im here" << std::endl;
    if (v->get_state() == prev_state) {
    std::cerr << "im here 2" << std::endl;
      v->update(curr_state);
    }
  }
}
