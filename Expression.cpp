#include "Expression.h"

bool Expression::operator<(const Expression &other) const {
    double leftOperand = this->calculate();
    double rightOperand = other.calculate();
    return leftOperand < rightOperand;
}
bool Expression::operator>(const Expression &other) const {
    double leftOperand = this->calculate();
    double rightOperand = other.calculate();
    return leftOperand > rightOperand;
}
bool Expression::operator<=(const Expression &other) const {
    double leftOperand = this->calculate();
    double rightOperand = other.calculate();
    return leftOperand <= rightOperand;
}
bool Expression::operator>=(const Expression &other) const {
    double leftOperand = this->calculate();
    double rightOperand = other.calculate();
    return leftOperand >= rightOperand;
}
bool Expression::operator==(const Expression &other) const {
    double leftOperand = this->calculate();
    double rightOperand = other.calculate();
    return leftOperand == rightOperand;
}