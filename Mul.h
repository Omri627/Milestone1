#ifndef MULTPICATION
    #define MULTPICATION

#include "SymbolTable.h"
#include "BInaryExpression.h"
class Mul : public BinaryExpression {
public:
    Mul(Expression * firstOperand, Expression * secondOperand);
    double calculate() const;
};


#endif
