#ifndef NUMBER_H
    #define NUMBER_H

#include "SymbolTable.h"
#include "Expression.h"

class Number : public Expression {
private:
    /* value of number */
    double value;
public:
    /**
     * the constructor creates Number object initialized with given value.
     * @param value  value of number
     */
    Number(double value);
    /**
    * calculate method computes this mathematical expression
    * and returns the result as real number.
    * @return returns number's value
    */
    virtual double calculate() const ;
    /**
     * getter of value value field
     * @return returns the value of this number
     */
    virtual double getValue() const ;
    /**
     * setValue sets the value of this number object with given value
     * @param value newly value
     */
    virtual void setValue(double value);
    /**
     * printExpression method prints out textual representation of this expression
     * infix mode representation
     */
    virtual void printExpression() const;
};


#endif
