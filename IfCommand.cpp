//
// Created by omri on 14/12/18.
//

#include "IfCommand.h"
#include "ConditionParser.h"
IfCommand::IfCommand(list<Command *> commands, Expression *rightExpression, Expression *leftExpression,
                           Expression::Relation relation) : ConditionParser(commands, rightExpression, leftExpression, relation) {

}
IfCommand::IfCommand(Expression *rightExpression, Expression *leftExpression, string relation)
: ConditionParser(rightExpression, leftExpression, relation) {

}
int IfCommand::execute() {
    if (checkCondition()) {
        for (Command * command : this->getCommands()) {
            command->execute();
        }
    }
    return 1;
}