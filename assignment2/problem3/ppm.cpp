#include "ppm.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
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
//  short grey_scale = 0;
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
//        grey_scale = 1;
      } else {
        throw "not a valid argument";
      }
    } catch (const char *message) {
      std::cerr << argv[i] << " " << message << std::endl;
      exit(EXIT_FAILURE);
    } catch (...) {
      std::cerr << "Error handling command arguments" << std::endl;
    }
  }
  const PpmImage * const new_file=read_ppm();
  std::cout << new_file->len << std::endl;
  return 0;
}

// Look at header file for description
const PpmImage *read_ppm() {
  std::cout.exceptions(std::ofstream::failbit | std::ofstream::badbit);
  std::cerr.exceptions(std::ofstream::failbit | std::ofstream::badbit);
  std::cin.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try {
    auto *return_file = new PpmImage;
    string garbage;
    std::cin >> garbage;
    std::cin >> return_file->len;
    std::cin >> return_file->height;
    if (return_file->len <= 0 || return_file->height <= 0) {
      throw "incorrect length or height";
    }
    std::cin >> return_file->colourmax;
    return_file->pixels = new PpmImage::Pixel *[return_file->height];
    for (unsigned int i = 0; i < return_file->height; ++i) {
      return_file->pixels[i] = new PpmImage::Pixel[return_file->len];
    }
    for (unsigned int i = 0; i < return_file->height; ++i) {
     for (unsigned int j = 0; j < return_file->len; ++j) {
       std::cin.read(reinterpret_cast<char *>(&(return_file->pixels[i][j].r)), sizeof(char));
       std::cin.read(reinterpret_cast<char *>(&(return_file->pixels[i][j].g)), sizeof(char));
       std::cin.read(reinterpret_cast<char *>(&(return_file->pixels[i][j].b)), sizeof(char));
     }
    }
    return return_file;
  } catch (...) {
    exit(EXIT_FAILURE);
  }
}
