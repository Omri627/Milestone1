#ifndef ADDITION
    #define ADDITION

#include "BInaryExpression.h"

class Plus : public BinaryExpression {
public:
    Plus(double firstOperand, double secondOperand);

    Plus(Expression *firstOperand, Expression *secondOperand);

    virtual double calculate() const;

    void printExpression() const override;
};

#endif
