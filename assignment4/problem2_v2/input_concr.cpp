#include "input_concr.h"
#include <istream>
#include <string>

unsigned int Input_concr::read_value(std::istream &in) {
  unsigned int return_val;
  in >> return_val;
  return return_val;
}

std::string Input_concr::read_command(std::istream &in) {
  std::string return_val;
  in >> return_val;
  return return_val;
}
