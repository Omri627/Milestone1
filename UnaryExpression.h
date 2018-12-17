#ifndef UNARY_EXPRESSION
    #define UNARY_EXPRESSION

#include "Expression.h"
class UnaryExpression : public Expression {
private:
    Expression * operand;
public:
    UnaryExpression(Expression * operand);

    virtual Expression * getOperand() const ;
};


#endif
