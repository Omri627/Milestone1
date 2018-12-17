//
// Created by ranraboh on 14/12/18.
//

#ifndef PROJECT_NUMBER_H
#define PROJECT_NUMBER_H


#include "SymbolTable.h"
#include "Expression.h"

class Number : public Expression {
private:
    double value;
public:
    Number(double value);
    virtual double calculate() const ;
    virtual double getValue() const ;
    virtual void setValue(double value);
};


#endif
