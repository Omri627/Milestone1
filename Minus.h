#ifndef MINUS
    #define MINUS

#include "SymbolTable.h"
#include "BInaryExpression.h"
class Minus : public BinaryExpression {
public:
    /**
    * Minus constructor gets two operands and
    * creates minus object initialized with the given operands.
    * @param firstOperand first operand
    * @param secondOperand second operand
    **/
    Minus(Expression *firstOperand, Expression *secondOperand);
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

    virtual ~Minus();
};


#endif
