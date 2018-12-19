#ifndef CONDITION_PARSER
    #define CONDITION_PARSER


#include "CommandGenerator.h"
#include "CodeParser.h"

class ConditionParserGenerator : public CommandGenerator {
    CodeParser * codeParser;
    list<Command *> blockCommands;
public:
    ConditionParserGenerator();

    ConditionParserGenerator(CodeParser* codeParser);

    void setBlockCommands(list<Command *> commands);

    void setCodeParser(CodeParser * parser);

    void generateBlockCommands();

    void clearBlockCommands();

    list< Command* > getBlockCommands();

};


#endif //PROJECT_CONDITIONPARSERGENERATOR_H
