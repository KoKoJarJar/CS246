#include "utf8string.h"
#include <iostream>
#include <sstream>

void output(const utf8::string &str) {
  std::cout << str.length << " " << str.capacity << " " << str << std::endl;
}

int main() {
  using utf8::string;
  string s1;
  string s2("foobar");
  string s3("\xC2\xA3");
  string s4("\xD0\x87");
  string s5("");
  string s6 = s1;
  string s7 = s2;
  string s8 = s3;
  string s9 = s4;
  string s10 = s5;
  string s11 = string("\xDA\x98");
  string s12 = string("\xE1\x89\xBD");
  string s13 = string("\xF0\x9F\x9E\xAE");
  string s14 = s11;
  string s15 = s12;
  string s16 = s13;
  output(s1);
  output(s2);
  output(s3);
  output(s4);
  output(s5);
  output(s11);
  output(s12);
  output(s13);
  output(s6);
  output(s7);
  output(s8);
  output(s9);
  output(s10);
  output(s14);
  output(s15);
  output(s16);
  const char *test = "one two three";
  std::stringstream ss(test);
  ss >> s1 >> s2 >> s3;
  output(s1);
  output(s2);
  output(s3);
  output (s5 + s5);
  output (s6 + s5);
  output (s5 + s6);
  output (s6 + s6);
  output (s7 + s5);
  output (s5 + s7);
  output (s6 + s7);
  output (s7 + s6);
  output (s12 + s11);
  output (s11 + s12);
  output (s12 + s12);
  return 0;
}
