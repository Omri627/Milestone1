#include "WhileCommand.h"
#include "CodeParser.h"
/**
 * constructor
 * @param commands: command list to be excute
 * @param rightExpression: the right expression
 * @param leftExpression: the left expression
 * @param relation: the operator between the expression
 */
WhileCommand::WhileCommand(list<Command *> commands, Expression *rightExpression, Expression *leftExpression,
        Expression::Relation relation) : ConditionParser(commands, rightExpression, leftExpression, relation) {

}
/**
 * constructor
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