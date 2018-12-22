#include "UnaryExpression.h"
UnaryExpression::UnaryExpression(Expression *operand) {
    this->operand = operand;
}
void UnaryExpression::setOperand(Expression *operand) {
    this->operand = operand;
}
Expression* UnaryExpression::getOperand() const {
    return  this->operand;
}