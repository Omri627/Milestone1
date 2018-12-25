#include "BInaryExpression.h"
/**
 * BinaryExpression method gets two operand and
 * creates BinaryExpression object with given operands
 * @param firstOperand first operand
 * @param secondOperand second operand
 */
BinaryExpression::BinaryExpression(Expression *firstOperand, Expression *secondOperand) {
    this->firstOperand = firstOperand;
    this->secondOperand = secondOperand;
}
/**
 * getter method of first operand field
 * @return returns first operand of binary expression
 */
Expression * BinaryExpression::getFirstOperand() const {
    return this->firstOperand;
}
/**
  * getter method of second operand field
  * @return returns second operand of binary expression
  */
Expression * BinaryExpression::getSecondOperand() const {
    return this->secondOperand;
}
/*
 * setFirstOperand method sets first operand of this binary expression with given sub-expression
 * @param expression newly first operand expression
 */
void BinaryExpression::setFirstOperand(Expression *expression) {
    this->firstOperand = expression;
}
/*
 * setSecondOperand method sets second operand of this binary expression with given sub-expression
 * @param expression newly second operand expression
 */
void BinaryExpression::setSecondOperand(Expression *expression) {
    this->secondOperand = expression;
}
BinaryExpression::~BinaryExpression() {
    if (!this->firstOperand)
        delete(this->firstOperand);
    if (!this->secondOperand)
        delete(this->secondOperand);
}
