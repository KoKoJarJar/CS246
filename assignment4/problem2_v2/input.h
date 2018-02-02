#ifndef __INPUT__
#define __INPUT__

#include <istream>

class Input {
public:
  virtual unsigned int read_value(std::istream &in) = 0;
  virtual std::string read_command(std::istream &in) = 0;
};

#endif
