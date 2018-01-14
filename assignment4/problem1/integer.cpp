#include "integer.h"
#include <iostream>

Integer_expression::Integer_expression(){};

Integer_expression::Integer_expression(int value) {
  this->value = value;
}

void Integer_expression::prettyprint() {
  std::cout << value;
}

int Integer_expression::evaluate() {
  return value;
}

