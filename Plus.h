#ifndef ADDITION
    #define ADDITION

#include "BInaryExpression.h"

class Plus : public BinaryExpression {
public:
    /**
    * Plus constructor gets two numbers and
    * creates plus object initialized with the given operands.
    * @param firstOperand first operand real number
    * @param secondOperand second operand real number
    */
    Plus(double firstOperand, double secondOperand);
    /**
    * Plus constructor gets two operands and
    * creates plus object initialized with the given operands.
    * @param firstOperand first operand
    * @param secondOperand second operand
    */
    Plus(Expression *firstOperand, Expression *secondOperand);
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
    void printExpression() const override;
};

#endif
