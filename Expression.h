#ifndef EXPRESSION
    #define EXPRESSION

#include "SymbolTable.h"
class Expression {
public:
    /**
    * calculate method computes this mathematical expression
    * and returns the result as real number.
    * @return result of this mathematical expression
    */
    virtual double calculate() const = 0;
    /**
     * printExpression method prints out textual representation of this expression
     * infix mode representation
     */
    virtual void printExpression() const = 0;

    virtual bool operator<(const Expression &other) const;

    virtual  bool operator>(const Expression &other) const;

    virtual bool operator<=(const Expression &other) const;

    virtual bool operator>=(const Expression &other) const;

    virtual bool operator==(const Expression &other) const;

    virtual bool operator!=(const Expression &other) const;
    //@ todo not euqal
    enum Relation {
        G, GE, LE, L, E, NE
    };

    virtual ~Expression();


};


#endif
