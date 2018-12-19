#ifndef CONDITION_PARSER
    #define CONDITION_PARSER


#include "CommandGenerator.h"

class ConditionParserGenerator : public CommandGenerator {
    list<Command *> blockCommands;
public:
    ConditionParserGenerator();

    ConditionParserGenerator(list<Command*> blockCommands);

    void setBlockCommands(list<Command *> commands);

    void clearBlockCommands();

    list< Command* > getBlockCommands();
};


#endif //PROJECT_CONDITIONPARSERGENERATOR_H
