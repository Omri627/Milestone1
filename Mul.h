#ifndef MULTPICATION
    #define MULTPICATION

#include "SymbolTable.h"
#include "BInaryExpression.h"
class Mul : public BinaryExpression {
public:
    /**
    * Mul constructor gets two operands expressions and
    * creates plus object initialized with the given operands.
    * @param firstOperand first operand expression
    * @param secondOperand second operand expression
    */
    Mul(Expression *firstOperand, Expression *secondOperand);
    /**
    * calculate method computes this mathematical expression
    * and returns the result as real number.
    * @return result of this mathematical expression
    */
    double calculate() const;
    /**
     * printExpression method prints out textual representation of this expression
     * infix mode representation
     */
    virtual void printExpression() const;

    virtual ~Mul();
};


#endif
