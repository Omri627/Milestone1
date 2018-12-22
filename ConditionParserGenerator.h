#ifndef CONDITION_PARSER
    #define CONDITION_PARSER

#include "CommandGenerator.h"
#define INVALID_EXPRESSION "invalid expression"

class CodeParser;
class ConditionParserGenerator : public CommandGenerator {
    CodeParser *codeParser;
    list<Command *> blockCommands;
public:
    ConditionParserGenerator();

    virtual void setBlockCommands(list<Command *> commands);

    virtual void setCodeParser(CodeParser *parser);

    virtual void generateBlockCommands();

    virtual void clearBlockCommands();

    virtual list<Command *> getBlockCommands();

};
#endif
