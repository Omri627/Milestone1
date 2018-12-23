#include <iostream>
#include "Plus.h"
#include "Number.h"
/**
* Plus constructor gets two numbers and
* creates plus object initialized with the given operands.
* @param firstOperand first operand real number
* @param secondOperand second operand real number
*/
Plus::Plus(double firstOperand, double secondOperand)
: BinaryExpression(new Number(firstOperand), new Number(secondOperand)) {
}
/**
* Plus constructor gets two operands and
* creates plus object initialized with the given operands.
* @param firstOperand first operand
* @param secondOperand second operand
**/
Plus::Plus(Expression *firstOperand, Expression *secondOperand)
: BinaryExpression(firstOperand, secondOperand) {

}
/**
* calculate method computes this mathematical expression
* and returns the result as real number.
* @return result of this mathematical expression
*/
double Plus::calculate() const {
    /* computes first and second operands separately
    * and adds the results. */
    double firstOperand = this->getFirstOperand()->calculate();
    double secondOperand = this->getSecondOperand()->calculate();
    return firstOperand + secondOperand;
}
/**
 * printExpression method prints out textual representation of this expression
 * infix mode representation
 */
void Plus::printExpression() const {
    cout << "(";
    this->getFirstOperand()->printExpression();
    std::cout << " + ";
    this->getSecondOperand()->printExpression();
    cout << ")";
}
