//
// Created by omri on 14/12/18.
//

#ifndef MILESTONE1_CONDITIONPARSER_H
#define MILESTONE1_CONDITIONPARSER_H


#include <list>
#include <vector>
#include "Command.h"
#include "CodeReader.h"
#include "Expression.h"

class ConditionParser : public Command {

private:
    /* list of commands in block */
    list< Command * > commands;
    /* right expression in condition */
    Expression * rightExpression;
    /* left expression in condition */
    Expression * leftExpression;
    /* relation between left and right expression */
    Expression::Relation relation;
public:
    /**
     * creates Condition Parser object initialized with:
     * list of block commands, right and left expression of condition and the relation between them.
     * @param commands list of commands
     * @param rightExpression right expression in condition
     * @param leftExpression left expression in condition
     * @param relation relation between left and right expression
     */
    ConditionParser(list< Command * > commands, Expression * rightExpression,
            Expression * leftExpression, Expression::Relation relation);
    /**
     * creates Condition Parser object initialized with:
     * list of block commands, right and left expression of condition and the relation between them.
     * @param commands list of commands
     * @param rightExpression right expression in condition
     * @param leftExpression left expression in condition
     * @param relation relation between left and right expression
     */
    ConditionParser(list< Command * > commands, Expression * rightExpression, Expression * leftExpression, string relation);
    /**
     * check condition method check whether the condition is true or false.
     * @return condition result
     */
    virtual bool checkCondition();
    /**
     * setCondition method sets the condition of object:
     * i.e sets the right and left expression of condition and the relation between them.
     * @param rightExpression right expression in condition
     * @param leftExpression left expression in condition
     * @param relation relation between left and right expression
     */
    virtual void setCondition(Expression * left, Expression * right, Expression::Relation relation);
    /**
     * getCommands method returns the list of commands in block
     * @return returns the list of commands in block
     */
    const list<Command *> &getCommands() const;
    /**
     * getter method of relation field
     * @param relation relation between left and right expression
     * @return reutrns the relation between left and right expression
     */
    Expression::Relation getRelation(string relation);
    /**
     * destructor, free memory
     */
    virtual ~ConditionParser();
};


#endif //MILESTONE1_CONDITIONPARSER_H