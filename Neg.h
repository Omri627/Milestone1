#ifndef NEGETIVE
    #define NEGETIVE

#include "UnaryExpression.h"
class Neg : public UnaryExpression {
public:
    Neg(Expression* expression);
    /**
    * calculate method computes this mathematical expression
    * and returns the result as real number.
    * @return result of this mathematical expression
    */
    virtual double calculate() const ;
    /**
     * printExpression method prints out textual representation of this expression
     * infix mode representation
     */
    void printExpression() const override;
};


#endif
