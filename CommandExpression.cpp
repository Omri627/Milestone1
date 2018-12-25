#include "CommandExpression.h"
/**
 * creates CommandExpression object with given command.
 * i.e refer the commands as special type of expression
 * @param command command object
 */
CommandExpression::CommandExpression(Command *command) {
    this->command = command;
}
/**
 * calculate command expression with parameters is
 * defined as execute command with the given parameters
 * @return
 */
double CommandExpression::calculate() const {
    return this->command->execute();
}
CommandExpression::~CommandExpression() {
    delete this->command;
}