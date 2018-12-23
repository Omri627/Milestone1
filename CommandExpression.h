#ifndef COMMAND_EXPRESSION
    #define COMMAND_EXPRESSION

#include "Command.h"
#include "Expression.h"

class CommandExpression : public Expression {
private:
    Command * command;
public:
    CommandExpression(Command * command);

    double calculate() const override;
};


#endif //PROJECT_COMMANDEXPRESSION_H
