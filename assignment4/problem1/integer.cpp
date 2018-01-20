#include "integer.h"
#include <iostream>
#include <memory>
#include <utility>

Integer_expression::Integer_expression(){}

Integer_expression::Integer_expression(int value) {
  this->value = value;
}

void Integer_expression::prettyprint() {
  std::cout << value;
}

int Integer_expression::evaluate() {
  return value;
}

std::unique_ptr<Expression> Integer_expression::copy() {
  return std::unique_ptr<Expression>(new Integer_expression(*this));
}
