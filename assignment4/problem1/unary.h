#ifndef __UNARY__
#define __UNARY__

#include "expression.h"
#include <memory>
#include <string>

// class Unary extends expression by providing unary operations
class Unary : public Expression {
private:
  bool operation; // true for absolute value and false for negative
  std::unique_ptr<Expression> prev;
  Unary(const Unary &expr);

public:
  // default constructor for Unary
  Unary();

  // constructor for Unary 
  Unary(Expression &exp, std::string string);

  // prettyprint() same as abstract interface
  void prettyprint();

  // prettyprint() same as abstract interface
  int evaluate();

  // copy() same as abstract interface
  std::unique_ptr<Expression> copy();
};

#endif
