#include "WhileCommand.h"
#include "CodeParser.h"

WhileCommand::WhileCommand(list<Command *> commands, Expression *rightExpression, Expression *leftExpression,
        Expression::Relation relation) : ConditionParser(commands, rightExpression, leftExpression, relation) {

}
int WhileCommand::execute() {
    while (checkCondition()) {
        for (Command *command : this->getCommands()) {
            command->execute();
        }
    }
    return 1;
}