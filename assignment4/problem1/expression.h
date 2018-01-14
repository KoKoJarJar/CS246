#ifndef __EXPRESSION__
#define __EXPRESSION__

class Expression {
public:
  virtual void prettyprint() = 0;
  virtual int evaluate() = 0;
  virtual ~Expression() = 0;
};

#endif
