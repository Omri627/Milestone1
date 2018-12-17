#ifndef ADDITION
    #define ADDITION

#include "BInaryExpression.h"

class Plus : public BinaryExpression {
public:
    Plus(double firstOperand, double secondOperand);

    Plus(Expression *firstOperand, Expression *secondOperand);

    double calculate() const;
};

#endif
