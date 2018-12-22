#ifndef DIVISION
    #define DIVISION

#include "SymbolTable.h"
#include "BInaryExpression.h"
class Div : public BinaryExpression {
public:
    Div(Expression *firstOpernad, Expression *secondOperand);

    virtual double calculate() const;

    virtual void printExpression() const;
};


#endif
