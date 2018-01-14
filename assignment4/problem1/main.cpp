#include "binary.h"
#include "expression.h"
#include "integer.h"
#include "unary.h"
#include <iostream>
#include <stack>
#include <string>
#include <vector>

int main() {
  std::string input;
  std::stack<Expression *, std::vector<Expression *>> stack;
  while (true) {
    std::cin >> input;
    if (input == "NEG" || input == "ABS" || input == "+" || input == "-" || input == "/" ||
        input == "*") {
      break;
    }
    stack.push(new Integer_expression(std::stoi(input)));
  }
  while (!std::cin.eof()) {
    if (input != "NEG" && input != "ABS") {
      Expression &first = *(stack.top());
      stack.pop();
      Expression &second = *(stack.top());
      stack.pop();
      stack.push(new Binary(first, second, input));
      delete &first;
      delete &second;
    } else {
      Expression &first = *(stack.top());
      stack.pop();
      stack.push(new Unary(first, input));
      delete &first;
    }
    std::cin >> input;
  }
  Expression *result = stack.top();
  stack.pop();
  result->prettyprint();
  std::cout << std::endl;
  std::cout << result->evaluate() << std::endl;
  delete result;
  return 0;
}
