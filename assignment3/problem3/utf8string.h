#ifndef UTF8STRING_H
#define UTF8STRING_H
#include "utf8char.h"
#include <iostream>

namespace utf8 {
struct string {
  string();
  string(const string &);
  string(const char *);
  ~string();
  string &operator=(const string &);
  void push_back(Character ch);
  void reserve(unsigned int n);
  Character *chars;
  unsigned int length;
  unsigned int capacity;
};
} // namespace utf8
utf8::string operator+(const utf8::string &str1, const utf8::string &str2);
std::ostream &operator<<(std::ostream &outfile, const utf8::string &str);
std::istream &operator>>(std::istream &infile, utf8::string &str);
#endif /* end of include guard */
