#include "ConditionParser.h"
#include "Expression.h"
#include<algorithm>
#include <iostream>
/**
 * creates Condition Parser object initialized with:
 * list of block commands, right and left expression of condition and the relation between them.
 * @param commands list of commands
 * @param rightExpression right expression in condition
 * @param leftExpression left expression in condition
 * @param relation relation between left and right expression
 */
ConditionParser::ConditionParser(list<Command *> commands, Expression *rightExpression, Expression *leftExpression,
                                 Expression::Relation relation) {
        this->rightExpression = rightExpression;
        this->leftExpression = leftExpression;
        this->commands = commands;
        this->relation = relation;
}
/**
 * creates Condition Parser object initialized with:
 * list of block commands, right and left expression of condition and the relation between them.
 * @param commands list of commands
 * @param rightExpression right expression in condition
 * @param leftExpression left expression in condition
 * @param relation relation between left and right expression
 */
ConditionParser::ConditionParser(list<Command *> commands, Expression *rightExpression, Expression *leftExpression, string relation) {
    this->commands = commands;
    this->rightExpression = rightExpression;
    this->leftExpression = leftExpression;
    this->relation = this->getRelation(relation);
}
/**
 * setCondition method sets the condition of object:
 * i.e sets the right and left expression of condition and the relation between them.
 * @param rightExpression right expression in condition
 * @param leftExpression left expression in condition
 * @param relation relation between left and right expression
 */
void ConditionParser::setCondition(Expression * left, Expression * right, Expression::Relation relation) {
    this->leftExpression = leftExpression;
    this->rightExpression = rightExpression;
    this->relation = relation;
}
/**
 * check condition method check whether the condition is true or false.
 * @return condition result
 */
bool ConditionParser::checkCondition() {
    if (!this->rightExpression || !this->leftExpression)
        throw "condition did not defined";
    switch (this->relation) {
        case Expression::G:
            return *this->leftExpression > *this->rightExpression;
        case Expression::GE:
            return *this->leftExpression >= *this->rightExpression;
        case Expression::LE:
            return *this->leftExpression <= *this->rightExpression;
        case Expression::L:
            return *this->leftExpression < *this->rightExpression;
        case Expression::E:
            return *this->leftExpression == *this->rightExpression;
        case Expression::NE:
            return *this->leftExpression != *this->rightExpression;
    }
}
/**
 * getCommands method returns the list of commands in block
 * @return returns the list of commands in block
 */
const list<Command *> &ConditionParser::getCommands() const {
    return this->commands;
}
/**
 * getter method of relation field
 * @param relation relation between left and right expression
 * @return reutrns the relation between left and right expression
 */
Expression::Relation ConditionParser::getRelation(string relation) {
    if (!relation.compare(">"))
        return Expression::G;
    if (!relation.compare(">="))
        return Expression::GE;
    if (!relation.compare("<"))
        return Expression::L;
    if (!relation.compare("<="))
        return Expression::LE;
    if (!relation.compare("=="))
        return Expression::E;
    if (!relation.compare("!="))
        return Expression::NE;
    throw "relation is invalid";
}
/**
 * destructor, free memory
 */
ConditionParser::~ConditionParser() {
    //delete this->leftExpression;
    //delete this->rightExpression;
    for (Command * command : this->commands)
        delete command;
}
