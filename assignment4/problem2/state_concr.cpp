#include "state_concr.h"


State_concr::State_concr(unsigned int input = 0) {
  color = input;
}

unsigned int State_concr::get_value() {
  return color;
}

void State_concr::set_value(unsigned int input) {
  color = input;
}
