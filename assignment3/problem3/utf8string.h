#ifndef UTF8STRING_H
#define UTF8STRING_H
#include "utf8char.h"
#include <iostream>

namespace utf8 {
// class string, aimed to represent a utf8 encoded string
struct string {

  // default constructor
  string();

  // string(str) constructs a utf8 string based on str
  // complexity: O(n) where n is the length of str
  // exception handling: throws ios_base::failure in case of 
  // invalid str and UTF8err in case of str null
  string(const string &);

  // string(str) constructs a utf8 string based on another
  // utf8 string
  // complexity: O(n) where n is the length of str
  string(const char *);

  // destructor
  // complexity: O(n) where n is the length of the string
  ~string();

  // =(string) performs the assignment operator based on the 
  // utf8 string, string
  // complexity: O(n) where n is the length of string
  string &operator=(const string &);

  // push_back(ch) adds a utf8 character to the object
  void push_back(Character ch);

  // reserve(n) adds to the capacity of the object based on n
  // complexity: O(n) 
  // note: does not add capacity unless necessary
  void reserve(unsigned int n);

  Character *chars;
  unsigned int length;
  unsigned int capacity;
};
} // namespace utf8

// +(str1, str2) appends str2 to str1
// effects: none
// complexity: O(n) where n is str1.length + str2.length
utf8::string operator+(const utf8::string &str1, const utf8::string &str2);

// <<(outfile, str) outputs utf8 encoded string to outfile and returns outfile
// effects: I/O
// complexity: I/O + O(n)
std::ostream &operator<<(std::ostream &outfile, const utf8::string &str);

// >>(infile, str) attemps to read a utf8 encoded string from infile to str
// and returns infile
// effects: I/O
// complexity: I/O + O(n) where n is the prospective length of str
// requires: infile must be a utf8 encoded stream
std::istream &operator>>(std::istream &infile, utf8::string &str);
#endif /* end of include guard */
