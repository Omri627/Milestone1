#include "Mul.h"
#include "Expression.h"
Mul::Mul(Expression *firstOperand, Expression *secondOperand)
: BinaryExpression(firstOperand, secondOperand) {

}
double Mul::calculate() const {
    double firstOperand = this->getFirstOperand()->calculate();
    double secondOperand = this->getSecondOperand()->calculate();
    return firstOperand * secondOperand;
}
