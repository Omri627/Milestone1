#ifndef COMMAND_EXPRESSION
    #define COMMAND_EXPRESSION

#include "Command.h"
#include "Expression.h"

class CommandExpression : public Expression {
/* using object adapter design
 * for classes expression and command which have incompatible interfaces to work together
*/
private:
    /* command object */
    Command * command;
public:
    /**
     * creates CommandExpression object with given command.
     * i.e refer the commands as special type of expression
     * @param command command object
     */
    CommandExpression(Command * command);
    /**
     * calculate command expression with parameters is
     * defined as execute command with the given parameters
     * @return
     */
    virtual double calculate() const;
    /**
     * destructor, free memory
     */
    virtual ~CommandExpression();
};


#endif