#include "WhileCommand.h"
#include "CodeParser.h"
/**
 * the constructor creates while commands with the given
 * commands in loop block and the condition composed of
 * right and left expression and the relation between them.
 * @param commands: command list to be excute
 * @param rightExpression: the right expression in condition
 * @param leftExpression: the left expression in condition
 * @param relation: the operator between the expression
 */
WhileCommand::WhileCommand(list<Command *> commands, Expression *rightExpression, Expression *leftExpression,
        Expression::Relation relation) : ConditionParser(commands, rightExpression, leftExpression, relation) {

}
/**
* the constructor creates while commands with the given
* commands in loop block and the condition composed of
* right and left expression and the relation between them.
* @param commands: command list to be excute
* @param rightExpression: the right expression
* @param leftExpression: the left expression
* @param relation: the operator between the expression
*/
WhileCommand::WhileCommand(list< Command * > commands, Expression *rightExpression, Expression *leftExpression, string relation)
: ConditionParser(commands, rightExpression, leftExpression, relation) {

}

/**
 * execute all he command inside the params
 * @return 1 if successful
 */
int WhileCommand::execute() {
    while (checkCondition()) {
        for (Command *command : this->getCommands()) {
            command->execute();
        }
    }
    return 1;
}

WhileCommand::~WhileCommand() {

}
