#include <iostream>
#include <type_traits>

template <typename T,
          typename std::enable_if<!std::is_default_constructible<T>::value, bool>::type = true>
T create_T(int i = 1) {
  std::cout << "construct" << std::endl;
  return T{i};
}

template <typename T,
          typename std::enable_if<std::is_default_constructible<T>::value, bool>::type = true>
T create_T() {
  std::cout << "default" << std::endl;
  return T{};
}

class D {};

class C {
public:
  int a;
  C(int a) : a(a){};
};

int main() {
  create_T<D>();
  create_T<C>();
}
