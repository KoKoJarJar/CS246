#include <iostream>
#include <memory>
#include <string>

template <typename T> class A {

public:
  static T mem[1];
  static bool allocated;
  static void *operator new(std::size_t size) {
    std::cerr << "hello there" << std::endl;
    if (allocated) {
      throw std::string("already allocated");
    }
    allocated = true;
    return mem;
  }
  static void operator delete(void *val) {
    std::cerr << "hello there, delete" << std::endl;
    allocated = false;
  }
};

template <typename T> bool A<T>::allocated = false;
template <typename T> T A<T>::mem[1];

int main() {
  A<int> *test = new A<int>;
  // should throw
  try {
    A<int> *test_2 = new A<int>;
  } catch (std::string &s) {
    std::cerr << s << std::endl;
  }
  delete test;
  A<int> *test2 = new A<int>;
  delete test2;
}
