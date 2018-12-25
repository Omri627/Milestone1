#ifndef PROJECT_WHILECOMMAND_H
#define PROJECT_WHILECOMMAND_H


#include "ConditionParser.h"

class WhileCommand : public ConditionParser {
public:
/**
 * the constructor creates while commands with the given
 * commands in loop block and the condition composed of
 * right and left expression and the relation between them.
 * @param commands: command list to be excute
 * @param rightExpression: the right expression in condition
 * @param leftExpression: the left expression in condition
 * @param relation: the operator between the expression
 */
    WhileCommand(list<Command *> commands, Expression *rightExpression, Expression *leftExpression,
                 Expression::Relation relation);

 /**
 * the constructor creates while commands with the given
 * commands in loop block and the condition composed of
 * right and left expression and the relation between them.
 * @param commands: command list to be excute
 * @param rightExpression: the right expression
 * @param leftExpression: the left expression
 * @param relation: the operator between the expression
 */
    WhileCommand(list< Command * > commands, Expression *rightExpression, Expression *leftExpression,
                 string relation);
/**
 * execute all the commands inside the block
 * @return 1 if successful
 */
    virtual int execute() ;

    virtual ~WhileCommand();
};


#endif //PROJECT_WHILECOMMAND_H
