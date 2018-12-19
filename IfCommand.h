#ifndef MILESTONE1_IFCOMMAND_H
#define MILESTONE1_IFCOMMAND_H

#include "ConditionParser.h"
#include "CodeParser.h"

class IfCommand : public ConditionParser {
public:
    IfCommand(list<Command *> commands, Expression *rightExpression, Expression *leftExpression,
              Expression::Relation relation);

    IfCommand(list< Command * > commands, Expression *rightExpression, Expression *leftExpression, string relation);

    virtual int execute();
};
#endif
