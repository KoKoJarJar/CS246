#ifndef UTF8STRING_H
#define UTF8STRING_H
#include "utf8char.h"

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

#endif /* end of include guard */
