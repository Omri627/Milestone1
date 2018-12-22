#ifndef EXPRESSION
    #define EXPRESSION

#include "SymbolTable.h"
class Expression {
private:
    SymbolTable* symbolTable;
public:

    virtual double calculate() const = 0;

    virtual void printExpression() const = 0;

    virtual bool operator<(const Expression &other) const;

    virtual  bool operator>(const Expression &other) const;

    virtual bool operator<=(const Expression &other) const;

    virtual bool operator>=(const Expression &other) const;

    virtual bool operator==(const Expression &other) const;
    // todo: implement !=
    enum Relation {
        G, GE, LE, L, E
    };


};


#endif
