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
    /**
    * '<' operator compare between two expression
    * and return whether left operand is lesser then right operand
    * @param other another expression for comparision
    * @return return true if left operand is lesser then right operand
    * at any other case return false
    */
    virtual bool operator<(const Expression &other) const;
    /**
    * '>' operator compare between two expression
    * and return whether left operand is bigger then right operand
    * @param other another expression for comparision
    * @return return true if left operand is bigger then right operand
    * at any other case return false
    */
    virtual  bool operator>(const Expression &other) const;
    /**
    * '<=' operator compare between two expression
    * and return whether left operand is lesser or equal then right operand
    * @param other another expression for comparision
    * @return return true if left operand is lesser or equal then right operand
    * at any other case return false
    */
    virtual bool operator<=(const Expression &other) const;
    /**
    * '>=' operator compare between two expression
    * and return whether left operand is bigger or equal then right operand
    * @param other another expression for comparision
    * @return return true if left operand is bigger or equal then right operand
    * at any other case return false
    */
    virtual bool operator>=(const Expression &other) const;
    /**
    * '==' operator compare between two expression
    * and return true if two expression are equal.
    * @param other another expression for comparision
    * @return return true if left operand is equal to right operand
    * at any other case return false
    */
    virtual bool operator==(const Expression &other) const;
    /**
    * '!=' operator compare between two expression
    * and return true if two expression are not equal.
    * @param other another expression for comparision
    * @return return true if left operand is not equal to right operand
    * at any other case return false
    */
    virtual bool operator!=(const Expression &other) const;
    enum Relation {
        G, GE, LE, L, E, NE
    };
    /**
     * destructor, free memory
     */
    virtual ~Expression();


};


#endif
