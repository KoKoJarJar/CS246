#include "ppm.h"
#include <iostream>
#include <sstream>
#include <string>

using std::string;

struct PpmImage {
  struct Pixel {
    unsigned char r, g, b;
  };
  unsigned int len, height, colourmax;
  Pixel **pixels;
};

int main(int argc, char const *argv[]) {
  short tranpose = 0;
  short vertical = 0;
  short grey_scale = 0;
  for (int i = 1; i < argc; ++i) {
    try {
      const string option(argv[i]);
      if (option == "-v") {
        ++vertical;
        vertical %= 2;
      } else if (option == "-t") {
        ++tranpose;
        tranpose %= 2;
      } else if (option == "-g") {
        grey_scale = 1;
      } else {
        throw "not a valid argument";
      }
    } catch (const char * message) {
      std::cout << argv[i] << " " << message << std::endl;
    } catch (...) {
      std::cout << "Error handling command arguments" << std::endl;
    }
  }
return 0;
}
