#include "cell.h"
#include "grid_concr.h"
#include <memory>
#include <vector>

Grid_concr::Grid_concr(unsigned int size, unsigned int max_state, const std::vector<Cell *> &grid)
    : size(size), max_state(max_state) {
  const unsigned int length = size * size;
  if (grid.size() != length) {
    throw "error";
  }
  for (auto v : grid) {
    if (v == nullptr) {
      throw "error";
    }
    if (v->get_state() > max_state) {
      throw "error";
    }
    this->grid.push_back(std::unique_ptr<Cell>(v));
  }
}

unsigned int Grid_concr::index(unsigned int i, unsigned int j) const {
  if (i >= size || j >= size) {
    throw "error";
  }
  return i * size + j;
}

bool Grid_concr::update(unsigned int i, unsigned int j, unsigned int value) {
  unsigned int index = this->index(i, j);
  if (value > max_state) {
    return false;
  }
  grid[index].get()->update(value);
  return true;
}

unsigned int Grid_concr::get_size() const {
  return size;
}

unsigned int Grid_concr::get_max_state() const {
  return max_state;
}

bool Grid_concr::is_equal() const {
  Cell &first = *(grid[0].get());
  for (const auto &v : grid) {
    if (*(v.get()) != first) {
      return false;
    }
  }
  return true;
}

const Cell &Grid_concr::get_cell(unsigned int i, unsigned int j) const {
  unsigned int index = this->index(i, j);
  return *(grid[index].get());
}
