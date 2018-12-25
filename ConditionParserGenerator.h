#ifndef CONDITION_PARSER
    #define CONDITION_PARSER

#include "CommandGenerator.h"
#define INVALID_EXPRESSION "invalid expression"

class CodeParser;
class ConditionParserGenerator : public CommandGenerator {
    /* code paraser used to read commands in block */
    CodeParser *codeParser;
    /* command in block */
    list<Command *> blockCommands;
public:
    /*
     * default constructor
     */
    ConditionParserGenerator();

    ConditionParserGenerator(CodeParser * codeParser);

    virtual void setBlockCommands(list<Command *> commands);

    virtual void setCodeParser(CodeParser *parser);

    virtual void generateBlockCommands();

    virtual ~ConditionParserGenerator();

    virtual void clearBlockCommands();

    virtual list<Command *> getBlockCommands();

};
#endif
