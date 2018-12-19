#ifndef WHILE_COMMAND_GENERATOR
    #define WHILE_COMMAND_GENERATOR

#include "Command.h"
#include "ExpressionParser.h"
#include "WhileCommand.h"
#include "ConditionParserGenerator.h"
class WhileCommandGenerator : public ConditionParserGenerator {
public:
    WhileCommandGenerator();

    WhileCommandGenerator(list<Command *> commands);

    virtual Command *create(CodeReader &codeReader);

};


#endif
