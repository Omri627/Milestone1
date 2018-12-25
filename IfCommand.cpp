
#include "IfCommand.h"
#include "ConditionParser.h"
IfCommand::IfCommand(list<Command *> commands, Expression *rightExpression, Expression *leftExpression,
                           Expression::Relation relation) : ConditionParser(commands, rightExpression, leftExpression, relation) {

}
IfCommand::IfCommand(list< Command * > commands, Expression *rightExpression, Expression *leftExpression, string relation)
: ConditionParser(commands, rightExpression, leftExpression, relation) {

}
int IfCommand::execute() {
    if (checkCondition()) {
        for (Command * command : this->getCommands()) {
            command->execute();
        }
    }
    return 1;
}

IfCommand::~IfCommand() {
}
