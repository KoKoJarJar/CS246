#include <iostream>
#include <type_traits>

template <typename T> inline decltype(auto) my_move(T &t) {
  return static_cast<typename std::remove_reference<T>::type &&>(t);
}

int main() {
  auto boz = 5;
  auto &maow = boz;
  my_move(maow);
}
