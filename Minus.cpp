#include <iostream>
#include "Minus.h"
#include "Expression.h"
/**
* Minus constructor gets two operands and
* creates minus object initialized with the given operands.
* @param firstOperand first operand
* @param secondOperand second operand
**/
Minus::Minus(Expression *firstOperand, Expression *secondOperand): BinaryExpression(firstOperand, secondOperand) {
}
/**
 * calculate method computes this mathematical expression
 * and returns the result as real number.
 * @return result of this mathematical expression
 */
double Minus::calculate() const {
    /* computes first and second operands separately
    * and decrease second operand result from first operand result. */
    double firstOperand = this->getFirstOperand()->calculate();
    double secondOperand = this->getSecondOperand()->calculate();
    return firstOperand - secondOperand;
}
/**
 * printExpression method prints out textual representation of this expression
 * infix mode representation
 */
void Minus::printExpression() const {
    cout << "(";
    this->getFirstOperand()->printExpression();
    std::cout << " - ";
    this->getSecondOperand()->printExpression();
    cout << ")";
}