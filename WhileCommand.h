#ifndef PROJECT_WHILECOMMAND_H
#define PROJECT_WHILECOMMAND_H


#include "ConditionParser.h"

class WhileCommand : public ConditionParser {
public:
/**
 * constructor
 * @param commands: command list to be excute
 * @param rightExpression: the right expression
 * @param leftExpression: the left expression
 * @param relation: the operator between the expression
 */
    WhileCommand(list<Command *> commands, Expression *rightExpression, Expression *leftExpression,
                 Expression::Relation relation);

 /**
 * constructor
 * @param commands: command list to be excute
 * @param rightExpression: the right expression
 * @param leftExpression: the left expression
 * @param relation: the operator between the expression
 */
    WhileCommand(list< Command * > commands, Expression *rightExpression, Expression *leftExpression,
                 string relation);
/**
 * execute all he command inside the params
 * @return 1 if successful
 */
    virtual int execute() ;
};


#endif //PROJECT_WHILECOMMAND_H
