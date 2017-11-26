#include "utf8char.h"
#include "utf8string.h"
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>

// look at header for description
utf8::string::string() : chars(nullptr), length(0), capacity(0){};

// look at header for description
utf8::string::string(const string &str)
    : chars(nullptr), length(str.length), capacity(str.capacity) {
  if (capacity == 0) {
    return;
  }
  chars = new Character[capacity];
  std::memcpy(chars, str.chars, sizeof(Character) * length);
}

// look at header for description
utf8::string::string(const char *str) : utf8::string() {
  if (str == nullptr) {
    throw UTF8err("constructor called with null");
  }
  std::stringstream input(str);
  if (!input.good()) {
    throw std::ios_base::failure("invalid string");
  }
  for (unsigned int i = 0;; ++i) {
    int check = input.peek();
    if (check == EOF) {
      break;
    }
    if (capacity == length) {
      this->reserve(2 * capacity);
    }
    read(input, chars[i]);
    ++length;
  }
}

// look at header for description
utf8::string::~string() {
  if (capacity == 0) {
    return;
  }
  delete[] chars;
}

// look at header for description
utf8::string &utf8::string::operator=(const string &string) {
  utf8::string temp(string);
  std::swap(length, temp.length);
  std::swap(capacity, temp.capacity);
  std::swap(chars, temp.chars);
  return *this;
}

// look at header for description
void utf8::string::push_back(Character ch) {
  if (length == capacity) {
    this->reserve(2 * capacity);
  }
  chars[length] = ch;
  ++length;
}

// look at header for description
void utf8::string::reserve(unsigned int n) {
  static const unsigned short min_allocation = 4;
  if (n < capacity) {
    return;
  }
  bool new_array = capacity == 0 ? true : false;
  if (new_array) {
    capacity = n > min_allocation ? n : min_allocation;
    chars = new Character[capacity];
    return;
  }
  capacity = n;
  auto *temp = new Character[capacity];
  std::memcpy(temp, chars, sizeof(Character) * length);
  std::swap(temp, chars);
  delete[] temp;
}

// look at header for description
utf8::string operator+(const utf8::string &str1, const utf8::string &str2) {
  utf8::string return_value(str1);
  return_value.reserve(str1.length + str2.length);
  return_value.length = str1.length + str2.length;
  for (unsigned int i = str1.length; i < return_value.length; ++i) {
    return_value.chars[i] = str2.chars[i - str1.length];
  }
  return return_value;
}

// <<(outfile, ch) outputs the character ch to outfile and returns outfile
// effects: I/O
// complexity: I/O 
std::ostream &operator<<(std::ostream &outfile, const Character &ch) {
  unsigned char output[5];
  for (unsigned int i = 0; i < ch.length; ++i) {
    output[i] = ch.data[i].ch;
  }
  output[ch.length] = '\0';
  outfile << output;
  return outfile;
}

// look at header for description
std::ostream &operator<<(std::ostream &outfile, const utf8::string &str) {
  for (unsigned int i = 0; i < str.length; ++i) {
    outfile << str.chars[i];
  }
  return outfile;
}

// >>(infile, ch) attempts to read a utf8 encoded char from infile to ch
// and returns infile
// effects: I/O
// complexity: I/O
// requires: infile must be a utf8 encoded stream
std::istream &operator>>(std::istream &infile, Character &ch) {
  try {
    read(infile, ch);
  } catch (UTF8err &err) {
    std::cerr << err.msg << std::endl;
  }
  return infile;
}

// look at header for description
std::istream &operator>>(std::istream &infile, utf8::string &str) {
  str = utf8::string();
  Character ch;
  for (unsigned int i = 0;; ++i) {
    infile >> std::ws;
    if (infile.eof()) {
      break;
    }
    infile >> ch;
    str.push_back(ch);
    int test = infile.peek();
    if (test == EOF || isspace(test)) {
      break;
    }
  }
  return infile;
}
