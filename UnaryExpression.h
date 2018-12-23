#ifndef UNARY_EXPRESSION
    #define UNARY_EXPRESSION

#include "Expression.h"
class UnaryExpression : public Expression {
private:
    /* operand of unary expression */
    Expression * operand;
public:
    /**
     * creates Unary Expression object with given operand
     * @param operand sub-expression operand
     */
    UnaryExpression(Expression * operand);
    /**
     * getter method of operand field
     * @return returns the operand of this unary expression
     */
    virtual Expression * getOperand() const ;
    /**
     * setOperand sets the operand of this unary expression
     * @param operand sub-expression operand
     */
    void setOperand(Expression * operand);
};


#endif
