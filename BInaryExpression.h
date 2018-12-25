#ifndef BINARY_EXPRESSION
    #define BINARY_EXPRESSION

#include "Expression.h"

class BinaryExpression : public Expression {
private:
    /* first operand of binary expression */
    Expression *firstOperand;
    /* second operand of binary expression */
    Expression *secondOperand;
public:
    /**
     * BinaryExpression method gets two operand and
     * creates BinaryExpression object with given operands
     * @param firstOperand first operand
     * @param secondOperand second operand
     */
    BinaryExpression(Expression *firstOperand, Expression *secondOperand);
    /**
     * getter method of first operand field
     * @return returns first operand of binary expression
     */
    Expression *getFirstOperand() const;
    /**
     * getter method of second operand field
     * @return returns second operand of binary expression
     */
    Expression *getSecondOperand() const;
    /*
     * setFirstOperand method sets first operand of this binary expression with given sub-expression
     * @param expression newly first operand expression
     */
    void setFirstOperand(Expression *expression);
    /*
     * setSecondOperand method sets second operand of this binary expression with given sub-expression
     * @param expression newly second operand expression
     */
    void setSecondOperand(Expression *expression);
    /**
     * destructor, free memory
     */
    ~BinaryExpression();
};

#endif
