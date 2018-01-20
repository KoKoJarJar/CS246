#ifndef __INTEGER__
#define __INTEGER__

#include "expression.h"

// class Integer_expression is the base case class for expression
// providing a value
class Integer_expression : public Expression {
private:
  int value;

public:
  // constructor for Integer_expression
  Integer_expression(int value);

  // same as above
  Integer_expression();

  // evaluate() same as abstract interface
  int evaluate();

  // prettyprint() same as abstract interface
  void prettyprint();

  // copy() same as abstract interface
  std::unique_ptr<Expression> copy();
};

#endif
