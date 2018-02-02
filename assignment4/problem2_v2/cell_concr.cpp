#include "cell_concr.h"

Cell_concr::Cell_concr() : state(0) {
}

Cell_concr::Cell_concr(unsigned int state) : state(state) {
}

unsigned int Cell_concr::get_state() const {
  return state;
}

bool Cell_concr::update(unsigned int state) {
  this->state = state;
  return true;
}

bool Cell_concr::operator==(const Cell &cell) const {
  return cell.get_state() == state;
}

bool Cell_concr::operator!=(const Cell &cell) const {
  return cell.get_state() != state;
}
