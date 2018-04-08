#ifndef __INPUT_CONCR__
#define __INPUT_CONCR__

#include "input.h"
#include <istream>
#include <string>

class Input_concr : public Input {
public:
  // see header for description
  unsigned int read_value(std::istream &in);

  // see header for description
  std::string read_command(std::istream &in);
};

#endif
