#include "error.h"
#include "unary.h"
#include <iostream>
#include <math.h>
#include <memory>
#include <utility>

Unary::Unary(Expression &exp, std::string string) : operation(false), prev(std::move(exp.copy())) {
  if (string == "NEG") {
    operation = false;
  } else if (string == "ABS") {
    operation = true;
  } else {
    throw Error("not a valid operation");
  }
}

Unary::Unary() : operation(false), prev(nullptr){}

int Unary::evaluate() {
  const int value = prev.get()->evaluate();
  if (operation == true) {
    return value >= 0 ? value : -value;
  }
  return -value;
}

void Unary::prettyprint() {
  if (operation == true) {
    std::cout << "|";
    (prev.get())->prettyprint();
    std::cout << "|";
    return;
  }
  std::cout << "-(";
  (prev.get())->prettyprint();
  std::cout << ")";
}

Unary::Unary(const Unary &expr)
    : operation(expr.operation), prev(std::move(expr.prev.get()->copy())){}

std::unique_ptr<Expression> Unary::copy() {
  return std::unique_ptr<Expression>(new Unary(*this));
}
