//
// Created by ranraboh on 14/12/18.
//

#include "Neg.h"
double Neg::calculate() const {
    Expression * operand = this->getOperand();
    return (-1) * operand->calculate();
}