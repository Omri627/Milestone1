#include "BInaryExpression.h"
BinaryExpression::BinaryExpression(Expression *firstOperand, Expression *secondOperand) {
    this->firstOperand = firstOperand;
    this->secondOperand = secondOperand;
}
Expression * BinaryExpression::getFirstOperand() const {
    return this->firstOperand;
}
Expression * BinaryExpression::getSecondOperand() const {
    return this->secondOperand;
}
void BinaryExpression::setFirstOperand(Expression *expression) {
    this->firstOperand = expression;
}
void BinaryExpression::setSecondOperand(Expression *expression) {
    this->secondOperand = expression;
}
