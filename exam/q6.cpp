#include <iostream>
#include <string>
#include <utility>

template <typename T> class A {
public:
  void old(T &t) {
    std::cout << "copy" << std::endl;
  }

  void old(T &&t) {
    std::cout << "move" << std::endl;
  }

  template <typename U = T> void newer(U &&u) {
    std::cout << "universal" << std::endl;
    old(std::forward<U>(u));
  }
};

class B {
};

int main() {
  std::string boz{"1 2 3"};
  A<std::string> test;
  test.old(boz);
  test.old("1 2 3");
  test.newer(boz);
  test.newer("1 2 3");
}
