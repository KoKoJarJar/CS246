#ifndef __INPUT__
#define __INPUT__

#include <istream>

// class Input which has the responsibility to obtain input
class Input {
public:
  // read_value(in) reads a value from input stream in
  // side effects: I/O
  virtual unsigned int read_value(std::istream &in) = 0;

  // read_command(in) reads a command from input stream in
  // side effects: I/O
  virtual std::string read_command(std::istream &in) = 0;
};

#endif
