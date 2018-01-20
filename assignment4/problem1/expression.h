#ifndef __EXPRESSION__
#define __EXPRESSION__

#include <memory>

// abstract class to evaluate binary and unary expressions
class Expression {
public:
  // prettyprint() prints expression
  // complexity: O(n) where n is the length of expression
  // exception handling: none
  // requires: valid expression
  virtual void prettyprint() = 0;

  // evaluate() evalues expression
  // complexity: O(n) where n is the length of expression
  // exception handling: throws Error if division by 0 is encountered
  // requires: valid expression
  virtual int evaluate() = 0;

  // ~Expression() destructor for expression
  virtual ~Expression() = 0;

  // copy() deep copies expression and creates a new safe pointer
  // complexity: O(n) where n is the depth of Expression
  // requires: valid expression
  virtual std::unique_ptr<Expression> copy() = 0;
};

#endif
