#ifndef _STRING_
#include <string>
#define _STRING_
#endif

// ppmimage holds the data to a ppm image
struct PpmImage;

// read_ppm(file_name) reads file_name and return a structure
// holding the data to a ppm image after reading the file
// effects: image is created and allocated (caller must free)
// complexity: I/O + O(mn) where m is the number of columns and
// n is the number of rows
// restrictions: only handles a P6 PPM
// exception_handling: throws exception when file_name does not
// match the format of a p6 PPM
PpmImage &read_ppm(std::string file_name);