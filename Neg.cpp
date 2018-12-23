#include <iostream>
#include "Neg.h"
Neg::Neg(Expression *expression) : UnaryExpression(expression) {
}
/**
 * calculate method computes this mathematical expression
 * and returns the result as real number.
 * @return result of this mathematical expression
 */
double Neg::calculate() const {
    Expression * operand = this->getOperand();
    return (-1) * operand->calculate();
}

void Neg::printExpression() const {
    cout << "( -";
    this->getOperand()->printExpression();
    cout << ")";
}
