#include <iostream>
#include "Div.h"
/**
* Div constructor gets two operands expressions and
* creates div object initialized with the given operands.
* @param firstOperand first operand expression
* @param secondOperand second operand expression
*/
Div::Div(Expression *firstOpernad, Expression *secondOperand)
: BinaryExpression(firstOpernad, secondOperand) {

}
/**
 * calculate method computes this mathematical expression
 * and returns the result as real number.
 * @return result of this mathematical expression
 */
double Div::calculate() const {
    /* computes numerator and denominator operands separately
    * and returns numerator result divided by denominator result */
    double numerator = this->getFirstOperand()->calculate();
    double denominator = this->getSecondOperand()->calculate();
    /* if denominator is equal 0, this expression is invalid */
    if (!denominator)
        throw "cannot divide by 0";
    return numerator / denominator;
}

/**
 * printExpression method prints out textual representation of this expression
 * infix mode representation
 */
void Div::printExpression() const {
    cout << "(";
    this->getFirstOperand()->printExpression();
    std::cout << " / ";
    this->getSecondOperand()->printExpression();
    cout << ")";
}
