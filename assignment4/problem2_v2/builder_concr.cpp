#include "builder_concr.h"
#include "cell.h"
#include "cell_concr.h"
#include "game.h"
#include "game_concr.h"
#include "grid.h"
#include "grid_concr.h"
#include "input.h"
#include "input_concr.h"
#include "printer.h"
#include "printer_concr.h"
#include "propagator.h"
#include "propagator_concr.h"
#include <cstdlib>
#include <vector>

Builder_concr::Builder_concr() {
}

Cell *Builder_concr::build_cell(unsigned int value) const {
  try {
    return new Cell_concr(value);
  } catch (...) {
    throw "not enough mem";
  }
}

Grid *Builder_concr::build_grid(unsigned int size, unsigned int max_state) const {
  try {
    std::vector<Cell *> grid;
    for (unsigned int i = 0; i < size * size; ++i) {
      grid.push_back(build_cell(rand() % (max_state + 1)));
    }
    return new Grid_concr(size, max_state, grid);
  } catch (...) {
    throw "not enough mem";
  }
}

Propagator *Builder_concr::build_propagator() const {
  try {
    return new Propagator_concr();
  } catch (...) {
    throw "not enough mem";
  }
}

Game *Builder_concr::build_game(unsigned int size, unsigned int max_state) const {
  try {
    Propagator *propagator = build_propagator();
    Grid *grid = build_grid(size, max_state);
    return new Game_concr(grid, propagator);
  } catch (...) {
    throw "not enough mem";
  }
}

Printer *Builder_concr::build_printer() const {
  try {
    return new Printer_concr();
  } catch (...) {
    throw "not enough mem";
  }
}

Input *Builder_concr::build_input() const {
  try {
    return new Input_concr();
  } catch (...) {
    throw "not enough mem";
  }
}
