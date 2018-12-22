#include <iostream>
#include "Neg.h"
Neg::Neg(Expression *expression) : UnaryExpression(expression) {
}
double Neg::calculate() const {
    Expression * operand = this->getOperand();
    return (-1) * operand->calculate();
}

void Neg::printExpression() const {
    cout << "( -";
    this->getOperand()->printExpression();
    cout << ")";
}
