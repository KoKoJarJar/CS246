#ifndef _STRING_
#include <string>
#define _STRING_
#endif

// ppmimage holds the data to a ppm image
struct PpmImage;

// read_ppm() return a structure holding the data to a 
// ppm image after reading the file
// effects: image is created and allocated (caller must free)
// complexity: I/O + O(mn) where m is the number of columns and
// n is the number of rows
// restrictions: only handles a P6 PPM
// exception_handling: throws exception of type const char * and cleans up
// in case of allocation error, exits the program
PpmImage *read_ppm();

// allocate_image() allocates and initializes a PpmImage 
// structure
// effects: image is created and allocated (caller must free)
// exception_handling: exits the program in case of bad_alloc
PpmImage *allocate_image();

// vertical_flip(image) transforms the image by doing a vertical flip
// effects: modifies image
// complexity: O(n) where n is the height of the image 
// restrictions: only handles a P6 PPM
// exception_handling: safe
void vertical_flip(PpmImage *image);

// transpose(image) transforms the image by doing a transpose
// effects: modifies image
// complexity: O(mn) where m and n are the width and height of the image
// restrictions: only handles a P6 PPM
// exception_handling: safe
void transpose(PpmImage *image);


// grey_scale(image) transforms the image by doing a grey_scale transformation
// effects: modifies image
// complexity: O(mn) where m and n are the width and height of the image
// restrictions: only handles a P6 PPM
// exception_handling: safe
void grey_scale(PpmImage *image);

// write_ppm(image) writes the ppm file to stdout
// complexity: I/O + O(mn) as read_ppm
// restrictions: only handles a P6 PPm
// exception_handling: safe
void write_ppm(PpmImage *image);

// dealloc_image(image) deallocates the image
// effects: deallocates the image
// restrictions: only handles a P6 PPM
void dealloc_image(PpmImage *image);
