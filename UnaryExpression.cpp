#include "UnaryExpression.h"
UnaryExpression::UnaryExpression(SymbolTable* st ,Expression *operand) {
    this->operand = operand;
}
Expression* UnaryExpression::getOperand() const {
    return  this->operand;
}