#include <iostream>
#include "Number.h"
/**
 * the constructor creates Number object initialized with given value.
 * @param value  value of number
 */
Number::Number(double value) {
    this->value = value;
}
/**
* calculate method computes this mathematical expression
* and returns the result as real number.
* @return returns number's value
*/
double Number::calculate() const {
    return this->value;
}
/**
 * getter of value value field
 * @return returns the value of this number
 */
double Number::getValue() const {
    return this->value;
}
/**
 * setValue sets the value of this number object with given value
 * @param value newly value
 */
void Number::setValue(double value) {
    this->value = value;
}
/**
 * printExpression method prints out textual representation of this expression
 * infix mode representation
 */
void Number::printExpression() const {
    cout << " " << this->value << " ";

}

