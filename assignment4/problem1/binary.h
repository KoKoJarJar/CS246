#ifndef __BINARY__
#define __BINARY__

#include "expression.h"
#include <memory>
#include <string>

class Binary : public Expression {
private:
  std::unique_ptr<Expression> left;
  std::unique_ptr<Expression> right;
  unsigned short operation; // 0 for + 1 for * 2 for / and 3 for -
  Binary(const Binary &expr);

public:
  // default constructor for Binary
  Binary();

  // alternative constructor for Binary
  Binary(Expression &left_val, Expression &right_val, std::string &string);

  // same as abstract interface
  void prettyprint();

  // same as abstract interface
  int evaluate();

  // same as abstract interface
  std::unique_ptr<Expression> copy();
};

#endif
