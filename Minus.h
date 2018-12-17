#ifndef MINUS
    #define MINUS


#include "SymbolTable.h"
#include "BInaryExpression.h"
class Minus : public BinaryExpression {
public:
    Minus(Expression * firstOperand, Expression* secondOperand);
    double calculate() const ;
};


#endif
