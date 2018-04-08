#include <iostream>
#include <map>
#include <string>
#include <utility>

class traversal;
class plus;
class variable;

class expression {
  virtual int visitor(traversal &) = 0;

public:
  int accept_visitor(traversal &trav) {
    return visitor(trav);
  }
  virtual ~expression() = 0;
};

expression::~expression(){};

class variable : public expression {
  std::string name;
  int visitor(traversal &trav) override;

public:
  variable(std::string name) : name(name){};
  const std::string &get_name() const {
    return name;
  }
};

class plus : public expression {
  expression *left, *right;
  int visitor(traversal &trav) override;

public:
  plus(expression *left, expression *right) : left(left), right(right){};
  expression *get_left() const {
    return left;
  }
  expression *get_right() const {
    return right;
  }
  ~plus() {
    delete left;
    delete right;
  }
};

class traversal {
public:
  virtual int eval(plus &) = 0;
  virtual int eval(variable &) = 0;
};

class evaluate_traversal : public traversal {
  std::map<std::string, int> var_values;

public:
  evaluate_traversal(std::initializer_list<std::pair<const std::string, int>> vals)
      : var_values{vals} {};

  int eval(plus &expr) override {
    return expr.get_left()->accept_visitor(*this) + expr.get_right()->accept_visitor(*this);
  }

  int eval(variable &expr) override {
    if (var_values.count(expr.get_name()) != 1) {
      return 0;
    }
    return var_values[expr.get_name()];
  }
};

int variable::visitor(traversal &trav) {
  return trav.eval(*this);
}

int plus::visitor(traversal &trav) {
  return trav.eval(*this);
}

int main() {
  auto expr = plus{new plus{new variable{"a"}, new variable{"b"}}, new variable{"c"}};
  expression &ptr = expr;
  auto trav = evaluate_traversal{{"a", 10}, {"b", 3}, {"c", 4}};
  traversal &ptr_trav = trav;
  std::cout << ptr.accept_visitor(ptr_trav) << std::endl;
}
