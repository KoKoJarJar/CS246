#ifndef __INTEGER__
#define __INTEGER__

#include "expression.h"

class Integer_expression : public Expression {
private:
  int value;

public:
  Integer_expression(int value);
  Integer_expression();
  int evaluate();
  void prettyprint();
};

#endif
