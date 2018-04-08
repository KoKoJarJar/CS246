#include <iostream>
#include <type_traits>

template <typename T> void f(typename std::remove_reference<T>::type &&arg) {
  std::cout << arg << std::endl;
}

int main() {
  f<int>(2);
}
