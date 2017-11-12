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
  unsigned int width, height, colourmax;
  Pixel **pixels;
};

int main(int argc, char const *argv[]) {
  short tran = 0;
  short vertical = 0;
  //  short grey_scale = 0;
  for (int i = 1; i < argc; ++i) {
    try {
      const string option(argv[i]);
      if (option == "-v") {
        ++vertical;
        vertical %= 2;
      } else if (option == "-t") {
        ++tran;
        tran %= 2;
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
  PpmImage *image = read_ppm();
  grey_scale(image);
  write_ppm(image);
  return 0;
}

// Look at header file for description
PpmImage *read_ppm() {
  std::cout.exceptions(std::ofstream::failbit | std::ofstream::badbit);
  std::cerr.exceptions(std::ofstream::failbit | std::ofstream::badbit);
  std::cin.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  bool completed = false;
  PpmImage *return_file = nullptr;
  try {
    return_file = allocate_image();
    string name;
    std::cin >> name;
    if (name != "P6") {
      throw "error";
    }
    std::cin >> return_file->width;
    std::cin >> return_file->height;
    if (static_cast<int>(return_file->width) <= 1 ||
        static_cast<int>(return_file->height) <= 1) {
      throw "error";
    }
    std::cin >> return_file->colourmax;
    std::cin.ignore(1);
    return_file->pixels = new PpmImage::Pixel *[return_file->height];
    for (unsigned int i = 0; i < return_file->height; ++i) {
      return_file->pixels[i] = new PpmImage::Pixel[return_file->width];
    }
    for (unsigned int i = 0; i < return_file->height; ++i) {
      for (unsigned int j = 0; j < return_file->width; ++j) {
        std::cin.read(reinterpret_cast<char *>(&(return_file->pixels[i][j].r)),
                      sizeof(unsigned char));
        std::cin.read(reinterpret_cast<char *>(&(return_file->pixels[i][j].g)),
                      sizeof(unsigned char));
        std::cin.read(reinterpret_cast<char *>(&(return_file->pixels[i][j].b)),
                      sizeof(unsigned char));
      }
    }
    completed = true;
    char useless = 0;
    std::cin.read(&useless, sizeof(char));
    throw "error";
  } catch (std::bad_alloc &err) {
    std::cerr << "allocation error, exiting" << std::endl;
    exit(EXIT_FAILURE);
  } catch (...) {
    if (completed) {
      return return_file;
    }
    // cleanup
    throw "I/O error, format of the file does not match a P6 PPM";
  }
}

// Look at header file for description
PpmImage *allocate_image() {
  PpmImage *return_file = nullptr;
  try {
    return_file = new PpmImage;
    return_file->width = 0;
    return_file->height = 0;
    return_file->colourmax = 0;
    return_file->pixels = nullptr;
    return return_file;
  } catch (...) {
    std::cerr << "allocation error, exiting" << std::endl;
    exit(EXIT_FAILURE);
  }
}

// Look at header file for description
void vertical_flip(PpmImage *image) {
  for (unsigned int i = 0; i < image->height / 2; ++i) {
    PpmImage::Pixel *temp = image->pixels[i];
    image->pixels[i] = image->pixels[image->height - 1 - i];
    image->pixels[image->height - 1 - i] = temp;
  }
}

// Look at header file for description
void transpose(PpmImage *image) {
  try {
    unsigned int temp = image->height;
    image->height = image->width;
    image->width = temp;
    PpmImage::Pixel **temp_pixels = image->pixels;
    image->pixels = new PpmImage::Pixel *[image->height];
    for (unsigned int i = 0; i < image->height; ++i) {
      image->pixels[i] = new PpmImage::Pixel[image->width];
    }
    for (unsigned int i = 0; i < image->height; ++i) {
      for (unsigned int j = 0; j < image->width; ++j) {
        image->pixels[i][j] = temp_pixels[j][i];
      }
    }
    for (unsigned int i = 0; i < image->width; ++i) {
      delete[] temp_pixels[i];
    }
    delete[] temp_pixels;
  } catch (...) {
    std::cerr << "allocation error, exiting" << std::endl;
    exit(EXIT_FAILURE);
  }
}

// Look at header file for description
void grey_scale(PpmImage *image) {
  for (unsigned int i = 0; i < image->height; ++i) {
    for (unsigned int j = 0; j < image->width; ++j) {
      unsigned char average = image->pixels[i][j].r / 3 +
                              image->pixels[i][j].g / 3 +
                              image->pixels[i][j].b / 3;
      image->pixels[i][j].b = average;
      image->pixels[i][j].g = average;
      image->pixels[i][j].r = average;
    }
  }
}

// Look at header file for description
void write_ppm(PpmImage *image) {
  std::cout << "P6 ";
  std::cout << image->width << " " << image->height;
  std::cout << " " << image->colourmax << std::endl;
  for (unsigned int i = 0; i < image->height; ++i) {
    for (unsigned int j = 0; j < image->width; ++j) {
      std::cout.write(reinterpret_cast<char *>(&(image->pixels[i][j].r)),
                      sizeof(unsigned char));
      std::cout.write(reinterpret_cast<char *>(&(image->pixels[i][j].g)),
                      sizeof(unsigned char));
      std::cout.write(reinterpret_cast<char *>(&(image->pixels[i][j].b)),
                      sizeof(unsigned char));
    }
  }
}
