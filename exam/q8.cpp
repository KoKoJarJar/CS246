#include <iomanip>
#include <iostream>
#include <type_traits>

template <typename...> using ignore_args = void;

template <typename, typename T> struct is_default_constructible_helper {
  static const bool value = false;
};
// here
template <typename T> struct is_default_constructible_helper<decltype(T{}), T> {
  static const bool value = true;
};

template <typename T>
struct is_default_constructible : public is_default_constructible_helper<T, T> {
};

class N {
public:
  N(int i) {
  }
};

int main() {
  std::cout << std::boolalpha;
  std::cout << is_default_constructible<int>::value << std::endl;
  std::cout << is_default_constructible<N>::value << std::endl;
  return 0;
}
