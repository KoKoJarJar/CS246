class C {
public:
  virtual void f() = 0;
  virtual ~C() = 0;
};

C::~C(){};

class D : public C {
public:
  virtual void f() override{};
};

class E : public C {
public:
  ~E(){};
};

class F : public C {
public:
  virtual void f() override{};
  ~F(){};
};

int main() {
  class D first;
  class F third;
}
