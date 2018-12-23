#include "UnaryExpression.h"
/**
 * creates Unary Expression object with given operand
 * @param operand sub-expression operand
 */
UnaryExpression::UnaryExpression(Expression *operand) {
    this->operand = operand;
}
/**
 * setOperand sets the operand of this unary expression
 * @param operand sub-expression operand
 */
void UnaryExpression::setOperand(Expression *operand) {
    this->operand = operand;
}
/**
* getter method of operand field
* @return returns the operand of this unary expression
*/
Expression* UnaryExpression::getOperand() const {
    return  this->operand;
}