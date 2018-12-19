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
    list< Command * > commands;
    Expression * rightExpression;
    Expression * leftExpression;
    Expression::Relation relation;
public:
    ConditionParser(list< Command * > commands, Expression * rightExpression,
            Expression * leftExpression, Expression::Relation relation);

    ConditionParser(list< Command * > commands, Expression * rightExpression, Expression * leftExpression, string relation);

    virtual bool checkCondition();

    virtual void setCondition(Expression * left, Expression * right, Expression::Relation relation);

    const list<Command *> &getCommands() const;

    Expression::Relation getRelation(string relation);
};


#endif //MILESTONE1_CONDITIONPARSER_H