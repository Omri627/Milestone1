#ifndef WHILE_COMMAND_GENERATOR
    #define WHILE_COMMAND_GENERATOR

#include "Command.h"
#include "ExpressionParser.h"
#include "WhileCommand.h"
#include "ConditionParserGenerator.h"
class WhileCommandGenerator : public ConditionParserGenerator {
public:
    /**
    * default constructor
    */
    WhileCommandGenerator();

    WhileCommandGenerator(CodeParser * codeParser);

    /**
    * this function crate the while command
    * @param codeReader: to get the next token
    * @return whileCommand*
    */
    virtual Command *create(CodeReader &codeReader);

};


#endif
