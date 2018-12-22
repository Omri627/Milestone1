#include <iostream>
#include "Minus.h"
#include "Expression.h"
Minus::Minus(Expression *firstOperand, Expression *secondOperand): BinaryExpression(firstOperand, secondOperand) {
}
double Minus::calculate() const {
    double firstOperand = this->getFirstOperand()->calculate();
    double secondOperand = this->getSecondOperand()->calculate();
    return firstOperand - secondOperand;
}
void Minus::printExpression() const {
    cout << "(";
    this->getFirstOperand()->printExpression();
    std::cout << " - ";
    this->getSecondOperand()->printExpression();
    cout << ")";
}