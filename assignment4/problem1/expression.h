#ifndef __EXPRESSION__
#define __EXPRESSION__

#include <memory>

class Expression {
public:
  virtual void prettyprint() = 0;
  virtual int evaluate() = 0;
  virtual ~Expression() = 0;
  virtual std::unique_ptr<Expression> copy() = 0;
};

#endif
