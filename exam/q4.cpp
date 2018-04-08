#include <iomanip>
#include <iostream>

class A {
public:
  void do_this() {
    std::cout << "lame" << std::endl;
  }

  int a = 1;
};

class B : public virtual A {
  int b = 2;
};

class C : public virtual A {
  int c = 3;
};

class D : public B, public C {
  int d = 4;
};

int main() {
  class D *boz = new D{};
  std::cout << std::hex << boz << std::endl;
  std::cout << std::hex << static_cast<D *>(boz) << std::endl;
  std::cout << std::hex << reinterpret_cast<D *>(boz) << std::endl;
  std::cout << std::hex << static_cast<C *>(boz) << std::endl;
  std::cout << std::hex << reinterpret_cast<C *>(boz) << std::endl;
  std::cout << std::hex << static_cast<A *>(boz) << std::endl;
  std::cout << std::hex << reinterpret_cast<A *>(boz) << std::endl;
  std::cout << std::hex << static_cast<B *>(boz) << std::endl;
  std::cout << std::hex << reinterpret_cast<B *>(boz) << std::endl;
}
