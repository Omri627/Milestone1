#ifndef NEGETIVE
    #define NEGETIVE

#include "UnaryExpression.h"
class Neg : public UnaryExpression {
public:
    Neg(Expression* expression);

    virtual double calculate() const ;

    void printExpression() const override;
};


#endif
