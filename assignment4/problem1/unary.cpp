#include "error.h"
#include "unary.h"
#include <iostream>

Unary::Unary(Expression &exp, std::string string) : operation(false), prev(&exp) {
  if (string == "NEG") {
    operation = false;
  } else if (string == "ABS") {
    operation = true;
  } else {
    throw Error("not a valid operation");
  }
}

Unary::Unary() : operation(false), prev(nullptr) {};

int Unary::evaluate() {
  return (prev.get())->evaluate();
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
