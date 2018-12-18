#ifndef CONDITION_PARSER
    #define CONDITION_PARSER


#include "CommandGenerator.h"

class ConditionParserGenerator : public CommandGenerator {
    Command *create(CodeReader &codeReader);
};


#endif //PROJECT_CONDITIONPARSERGENERATOR_H
