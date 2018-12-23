#include <iostream>
#include "Mul.h"
#include "Expression.h"
/**
* Mul constructor gets two operands expressions and
* creates plus object initialized with the given operands.
* @param firstOperand first operand expression
* @param secondOperand second operand expression
*/
Mul::Mul(Expression *firstOperand, Expression *secondOperand)
: BinaryExpression(firstOperand, secondOperand) {

}
/**
 * calculate method computes this mathematical expression
 * and returns the result as real number.
 * @return result of this mathematical expression
 */
double Mul::calculate() const {
    /* computes first and second operands separately
     * and multiplies the results. */
    double firstOperand = this->getFirstOperand()->calculate();
    double secondOperand = this->getSecondOperand()->calculate();
    return firstOperand * secondOperand;
}
/**
 * printExpression method prints out textual representation of this expression
 * infix mode representation
 */
void Mul::printExpression() const {
    cout << "(";
    this->getFirstOperand()->printExpression();
    std::cout << " * ";
    this->getSecondOperand()->printExpression();
    cout << ")";
}