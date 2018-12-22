#ifndef MINUS
    #define MINUS


#include "SymbolTable.h"
#include "BInaryExpression.h"
class Minus : public BinaryExpression {
public:
    Minus(Expression *firstOperand, Expression *secondOperand);

    virtual double calculate() const;

    virtual void printExpression() const;

};


#endif
