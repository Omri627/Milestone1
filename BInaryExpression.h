#ifndef BINARY_EXPRESSION
    #define BINARY_EXPRESSION

#include "Expression.h"

class BinaryExpression : public Expression {
private:
    Expression *firstOperand;
    Expression *secondOperand;
public:
    BinaryExpression(Expression *firstOperand, Expression *secondOperand);

    Expression *getFirstOperand() const;

    Expression *getSecondOperand() const;

    void setFirstOperand(Expression *expression);

    void setSecondOperand(Expression *expression);
};

#endif
