#ifndef DIVISION
    #define DIVISION

#include "SymbolTable.h"
#include "BInaryExpression.h"
class Div : public BinaryExpression {
public:
    Div(Expression * firstOpernad, Expression * secondOperand);
    double calculate() const ;
};


#endif
