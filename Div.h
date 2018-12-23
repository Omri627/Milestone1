#ifndef DIVISION
    #define DIVISION

#include "SymbolTable.h"
#include "BInaryExpression.h"
class Div : public BinaryExpression {
public:
    Div(Expression *firstOpernad, Expression *secondOperand);
    /**
    * calculate method computes this mathematical expression
    * and returns the result as real number.
    * @return result of this mathematical expression
    */
    virtual double calculate() const;
    /**
     * printExpression method prints out textual representation of this expression
     * infix mode representation
     */
    virtual void printExpression() const;
};


#endif
