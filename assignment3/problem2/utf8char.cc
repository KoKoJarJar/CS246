#include "utf8char.h"
#include <fstream>
#include <iostream>

// constructor for UTF8err
UTF8err::UTF8err(const char *msg) : msg(msg){};

// character_length(ch) determines the number of bytes needed 
// to represent a utf8 character based on ch's first byte
// restrictions: first byte of ch must be read beforehand
// complexity: O(1)
// exceptions: returns 0 if ch contains an invalid first byte
unsigned int character_length(const Character &ch) {
  if (ch.data[0].t1.ck == static_cast<unsigned char>(UTF8_length::one)) {
    return 1;
  }
  if (ch.data[0].t2.ck == static_cast<unsigned char>(UTF8_length::two)) {
    return 2;
  }
  if (ch.data[0].t3.ck == static_cast<unsigned char>(UTF8_length::three)) {
    return 3;
  }
  if (ch.data[0].t4.ck == static_cast<unsigned char>(UTF8_length::four)) {
    return 4;
  }
  return 0;
}

// is_valid_padding(ch, i) determines if the ith byte of ch is a valid
// padding
// restrictions: ch's ith byte must be read beforehand
bool is_valid_padding(Character ch, const int i) {
  return ch.data[i].dt.ck == static_cast<unsigned char>(UTF8_length::five);
}

// convert(ch) converts the formatted utf8 character in ch to
// a non-formatted utf8 char
// restrctions: requires a valid filled ch
wchar_t convert(const Character &ch) {
  const unsigned char shift = 6;
  wchar_t return_value = 0;
  switch (ch.length) {
  case 1:
    return_value = ch.data[0].t1.dt;
    break;
  case 2:
    return_value = ch.data[0].t2.dt;
    break;
  case 3:
    return_value = ch.data[0].t3.dt;
    break;
  case 4:
    return_value = ch.data[0].t4.dt;
    break;
  }
  for (unsigned int i = 1; i < ch.length; ++i) {
    return_value <<= shift;
    return_value += ch.data[i].dt.dt;
  }
  return return_value;
}

// is_valid_utf8(ch, val) determines if the non formatted utf8 character
// val is in the correct range based on ch
// restrictions: requires a valid filled ch
bool is_valid_utf8(const Character &ch, const wchar_t &val) {
  wchar_t low = 0, high = 0;
  switch (ch.length) {
  case 1:
    low = static_cast<wchar_t>(UTF8_bounds::first_low);
    high = static_cast<wchar_t>(UTF8_bounds::first_high);
    break;
  case 2:
    low = static_cast<wchar_t>(UTF8_bounds::second_low);
    high = static_cast<wchar_t>(UTF8_bounds::second_high);
    break;
  case 3:
    low = static_cast<wchar_t>(UTF8_bounds::third_low);
    high = static_cast<wchar_t>(UTF8_bounds::third_high);
    break;
  case 4:
    low = static_cast<wchar_t>(UTF8_bounds::fourth_low);
    high = static_cast<wchar_t>(UTF8_bounds::fourth_high);
    break;
  }
  return val >= low && val <= high;
}

// look at header for description
wchar_t read(std::istream &infile, Character &ch) {
  ch.length = 0;
  unsigned int length = 0;
  for (unsigned int i = 0;; ++i) {
    infile.read(reinterpret_cast<char *>(&ch.data[i].ch), sizeof(unsigned char));
    if (infile.eof()) {
      throw std::ios_base::failure("end of file reached");
    }
    if (!infile.good()) {
      throw std::ios_base::failure("I/O error");
    }
    ++ch.length;
    if (i == 0) {
      length = character_length(ch);
      if (length == 0) {
        throw UTF8err("invalid length");
      }
    } else {
      if (!is_valid_padding(ch, i)) {
        throw UTF8err("invalid padding");
      }
    }
    if (i == (length - 1)) {
      break;
    }
  }
  wchar_t return_value = convert(ch);
  if (!is_valid_utf8(ch, return_value)) {
    throw UTF8err("invalid range");
  }
  return return_value;
}
