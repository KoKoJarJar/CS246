#ifndef __UNARY__
#define __UNARY__

#include "expression.h"
#include <memory>
#include <string>

class Unary : public Expression {
private:
  bool operation; // true for absolute value and false for negative
  std::unique_ptr<Expression> prev;

public:
  Unary();
  Unary(Expression &exp, std::string string);
  void prettyprint();
  int evaluate();
};

#endif
