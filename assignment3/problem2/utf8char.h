#ifndef UTF8CHAR_H
#define UTF8CHAR_H
#include <fstream>

// UTF8 bounds based on which the UTF8 format is chosen
enum class UTF8_bounds : wchar_t {
  first_low = 0x0,
  first_high = 0x7f,
  second_low = 0x80,
  second_high = 0x7ff,
  third_low = 0x800,
  third_high = 0xFFFF,
  fourth_low = 0x10000,
  fourth_high = 0x10FFFF
};

// UTF8 constants which represent the starting bits of the first byte
enum class UTF8_length : unsigned char { one = 0, two = 6, three = 14, four = 30, five = 2 };

// structure to throw errors
struct UTF8err {
  const char *msg;
  UTF8err(const char *msg);
};

// structure which holds a utf8 character
struct Character {
  union UTF8 {
    unsigned char ch;
    struct {
      unsigned char dt : 7;
      unsigned char ck : 1;
    } t1;
    struct {
      unsigned char dt : 5;
      unsigned char ck : 3;
    } t2;
    struct {
      unsigned char dt : 4;
      unsigned char ck : 4;
    } t3;
    struct {
      unsigned char dt : 3;
      unsigned char ck : 5;
    } t4;
    struct {
      unsigned char dt : 6;
      unsigned char ck : 2;
    } dt;
  } data[4] = {};
  unsigned int length = 0;
};

// read(infile, ch) tries to read a utf8 formatted character from infile
// and stores it in ch, also outputs the corresponding non-formatted 
// utf8 character
// complexity: O(1)
// exception handling: in case of invalid character throws a UTF8err
// and in case of I/O failure throws a std::ios_base::failure
// restrictions: infile contains binary utf8 formatted data
wchar_t read(std::istream &infile, Character &ch);

#endif /* end of include guard */
