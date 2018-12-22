#ifndef IF_COMMAND_GENERATOR
    #define IF_COMMAND_GENERATOR

#include "IfCommand.h"
#include "Command.h"
class IfCommandGenerator : public ConditionParserGenerator {
public:
    IfCommandGenerator();

    IfCommandGenerator(CodeParser* codeParser);
    /**
    * this function crate the if command
    * @param codeReader: to get the next token
    * @return ifCommand*
    */
    virtual Command *create(CodeReader &codeReader);


};

#endif
