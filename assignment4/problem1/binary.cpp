#include "binary.h"
#include "error.h"
#include <iostream>
#include <string>

Binary::Binary() : left(nullptr), right(nullptr), operation(5){};

Binary::Binary(Expression &left_val, Expression &right_val, std::string string)
    : left(&left_val), right(&right_val), operation(5) {
  if (string == "+") {
    operation = 0;
  } else if (string == "*") {
    operation = 1;
  } else if (string == "-") {
    operation = 2;
  } else if (string == "/") {
    operation = 3;
  } else {
    throw Error("invalid operation");
  }
}

int Binary::evaluate() {
  if (operation == 0) {
    return (left.get())->evaluate() + (right.get())->evaluate();
  } else if (operation == 1) {
    return (left.get())->evaluate() * (right.get())->evaluate();
  } else if (operation == 2) {
    return (left.get())->evaluate() - (right.get())->evaluate();
  } else {
    int right_val = (right.get())->evaluate();
    if (right_val == 0) {
      throw Error("NaN");
    }
    return (left.get())->evaluate() / (right.get())->evaluate();
  }
}

void Binary::prettyprint() {
  std::cout << "(";
  (left.get())->prettyprint();
  if (operation == 0) {
    std::cout << " + ";
  } else if (operation == 1) {
    std::cout << " * ";
  } else if (operation == 2) {
    std::cout << " - ";
  } else {
    std::cout << " / ";
  }
  (right.get())->prettyprint();
  std::cout << ")";
}
