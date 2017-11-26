#include "utf8string.h"
#include <iostream>

int main() {
  using utf8::string;
  string s1;
  string s5 = s1;
  string s2("foobar");
  string s3(s2);
  string s4("\xC2\xA3");
  std::cout << s2 << " " << s3 << " " << s4 << " " << s5 << std::endl;
  std::cin >> s1 >> s4;
  std::cout << s1 << " " << s2 << " " << s3 << " " << s4 << std::endl;
  s1 = s1 + s4;
  s2 = s2 + "baz";
  std::cout << s1 << " " << s2 << std::endl;
  return 0;
}
