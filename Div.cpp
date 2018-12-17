#include "Div.h"
Div::Div(Expression *firstOpernad, Expression *secondOperand)
: BinaryExpression(firstOpernad, secondOperand) {

}
double Div::calculate() const {
    double numerator = this->getFirstOperand()->calculate();
    double denominator = this->getSecondOperand()->calculate();
    if (!denominator)
        throw "cannot divide by 0";
    return numerator / denominator;
}