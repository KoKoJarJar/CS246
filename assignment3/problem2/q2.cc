#include "utf8char.h"
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>

// error(msg) outputs msg to std::err
void error(const std::string &msg) {
  std::cerr << msg << std::endl;
  exit(EXIT_FAILURE);
}

// pre_output(ch) quick helper to output values or messages to std::cout
inline void pre_output(const Character &ch) {
  std::cout << std::hex << std::setfill('0');
  std::cout << "0x";
  for (unsigned int i = 0; i < ch.length; ++i) {
    std::cout << std::setw(2) << static_cast<unsigned int>(ch.data[i].ch);
  }
}

// output(msg, ch) outputs the value in ch and the corresponding msg 
void output(const UTF8err &msg, const Character &ch) {
  pre_output(ch);
  std::cout << " : ";
  std::cout << msg.msg << std::endl;
}

// output(msg, ch) outputs the value in ch and the 
// corresponding non-formatted value
void output(const wchar_t &utf8_val, const Character &ch) {
  pre_output(ch);
  std::cout << " : valid value 0x";
  std::cout << static_cast<unsigned int>(utf8_val) << std::endl;
}

int main(int argc, char const *argv[]) {
  std::istream *infile = &std::cin;
  switch (argc) {
  case 1:
    break;
  case 2:
    infile = new std::ifstream(argv[1]);
    if (!infile->good()) {
      delete infile;
      error("invalid filename");
    }
    break;
  default:
    error("invalid filename");
  }
  while (true) {
    Character ch;
    try {
      wchar_t utf8_val = read(*infile, ch);
      output(utf8_val, ch);
    } catch (UTF8err &msg) {
      output(msg, ch);
    } catch (std::ios_base::failure &err) {
      if (argc == 2) {
        delete infile;
      }
      if (ch.length == 0) {
        break;
      }
      error(err.what());
    } catch (...) {
      if (argc == 2) {
        delete infile;
      }
      error("unknown error");
    }
  }
}
