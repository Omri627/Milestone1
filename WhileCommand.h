//
// Created by ranraboh on 15/12/18.
//

#ifndef PROJECT_WHILECOMMAND_H
#define PROJECT_WHILECOMMAND_H


#include "ConditionParser.h"

class WhileCommand : public ConditionParser {
public:
    WhileCommand(list<Command *> commands, Expression *rightExpression, Expression *leftExpression,
                 Expression::Relation relation);

    WhileCommand(Expression *rightExpression, Expression *leftExpression,
                 string relation);

    virtual int execute() ;
};


#endif //PROJECT_WHILECOMMAND_H
