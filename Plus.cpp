#include <iostream>
#include "Plus.h"
#include "Number.h"

Plus::Plus(double firstOperand, double secondOperand)
: BinaryExpression(new Number(firstOperand), new Number(secondOperand)) {

}
Plus::Plus(Expression *firstOperand, Expression *secondOperand)
: BinaryExpression(firstOperand, secondOperand) {

}
double Plus::calculate() const {
    double firstOperand = this->getFirstOperand()->calculate();
    double secondOperand = this->getSecondOperand()->calculate();
    return firstOperand + secondOperand;
}

void Plus::printExpression() const {
    cout << "(";
    this->getFirstOperand()->printExpression();
    std::cout << " + ";
    this->getSecondOperand()->printExpression();
    cout << ")";
}
