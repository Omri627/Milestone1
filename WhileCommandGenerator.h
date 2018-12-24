
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
    /**
     * creates WhileCommandGenerator object with given code parser.
     * the code parser used to read the commands in block.
     * @param codeParser code parser object
     */
    WhileCommandGenerator(CodeParser * codeParser);

    /**
    * this method creates while command
    * @param codeReader: to get the next token
    * @return whileCommand*
    */
    virtual Command *create(CodeReader &codeReader);

};


#endif
