#include "Expression.h"
/**
 * '<' operator compare between two expression
 * and return whether left operand is lesser then right operand
 * @param other another expression for comparision
 * @return return true if left operand is lesser then right operand
 * at any other case return false
 */
bool Expression::operator<(const Expression &other) const {
    double leftOperand = this->calculate();
    double rightOperand = other.calculate();
    return leftOperand < rightOperand;
}
/**
 * '>' operator compare between two expression
 * and return whether left operand is bigger then right operand
 * @param other another expression for comparision
 * @return return true if left operand is bigger then right operand
 * at any other case return false
 */
bool Expression::operator>(const Expression &other) const {
    double leftOperand = this->calculate();
    double rightOperand = other.calculate();
    return leftOperand > rightOperand;
}
/**
 * '<=' operator compare between two expression
 * and return whether left operand is lesser or equal then right operand
 * @param other another expression for comparision
 * @return return true if left operand is lesser or equal then right operand
 * at any other case return false
 */
bool Expression::operator<=(const Expression &other) const {
    double leftOperand = this->calculate();
    double rightOperand = other.calculate();
    return leftOperand <= rightOperand;
}
/**
 * '>=' operator compare between two expression
 * and return whether left operand is bigger or equal then right operand
 * @param other another expression for comparision
 * @return return true if left operand is bigger or equal then right operand
 * at any other case return false
 */
bool Expression::operator>=(const Expression &other) const {
    double leftOperand = this->calculate();
    double rightOperand = other.calculate();
    return leftOperand >= rightOperand;
}
/**
 * '==' operator compare between two expression
 * and return true if two expression are equal.
 * @param other another expression for comparision
 * @return return true if left operand is equal to right operand
 * at any other case return false
 */
bool Expression::operator==(const Expression &other) const {
    double leftOperand = this->calculate();
    double rightOperand = other.calculate();
    return leftOperand == rightOperand;
}
/**
 * '!=' operator compare between two expression
 * and return true if two expression are not equal.
 * @param other another expression for comparision
 * @return return true if left operand is not equal to right operand
 * at any other case return false
 */
bool Expression::operator!=(const Expression &other) const {
    double leftOperand = this->calculate();
    double rightOperand = other.calculate();
    return leftOperand != rightOperand;
}

Expression::~Expression() {

}
