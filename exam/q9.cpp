#include <cstdlib>
#include <iostream>
#include <type_traits>
#include <utility>

class A;

template <typename T> class assignable {
protected:
  template <typename U> U &operator=(U &&u) {
    typename std::remove_reference<U>::type temp{std::forward<U>(u)};
    swap(temp, static_cast<T &>(*this));
    return static_cast<U &>(*this);
  }
};

class A {
public:
  int a;
  A(int a = 2) : a(a){};
};

class D : public assignable<D> {
public:
  A a;
  D(int a = 1) : a(a) {
    std::cout << "normal cons" << std::endl;
  }
  D(D &&other) noexcept : a(other.a) {
    std::cout << "move cons" << std::endl;
  }
  D(const D &other) : a(other.a) {
    std::cout << "copy cons" << std::endl;
  }
  D &operator=(D &d) {
    std::cout << "copy assignment" << std::endl;
    return assignable<D>::operator=(d);
  }
  D &operator=(D &&d) {
    std::cout << "move assignment" << std::endl;
    return assignable<D>::operator=(std::move(d));
  }
  friend void swap(D &, D &);
};

void swap(D &a, D &b) {
  A temp = b.a;
  b.a = a.a;
  a.a = temp;
}

int main() {
  D a0{0}, a1{3};
  a0 = a1;
  a0 = D{0};
  a0 = a0;
  a0 = D{2};
  D a3{D{5}};
  D a2{a1};
}
