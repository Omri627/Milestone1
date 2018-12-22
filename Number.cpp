#include <iostream>
#include "Number.h"
Number::Number(double value) {
    this->value = value;
}
double Number::calculate() const {
    return this->value;
}
double Number::getValue() const {
    return this->value;
}
void Number::setValue(double value) {
    this->value = value;
}

void Number::printExpression() const {
    cout << " " << this->value << " ";

}

