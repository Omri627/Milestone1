#ifndef IF_COMMAND_GENERATOR
    #define IF_COMMAND_GENERATOR

#include "IfCommand.h"
#include "Command.h"
class IfCommandGenerator : public ConditionParserGenerator {
public:
    IfCommandGenerator();

    IfCommandGenerator(list<Command *> commands);

    virtual Command *create(CodeReader &codeReader);


};

#endif
