#include "CommandExpression.h"
CommandExpression::CommandExpression(Command *command) {
    this->command = command;
}
double CommandExpression::calculate() const {
    return this->command->execute();
}
