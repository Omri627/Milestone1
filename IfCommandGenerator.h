#ifndef IF_COMMAND_GENERATOR
    #define IF_COMMAND_GENERATOR

#include "IfCommand.h"
#include "Command.h"
class IfCommandGenerator : public ConditionParserGenerator {
public:

    /**
    * default constructor
    */
    IfCommandGenerator();
    /**
     * creates If Command generator object initialized with code parser.
     * @param codeParser code parser object
     */
    IfCommandGenerator(CodeParser* codeParser);
    /**
    * create method creates if command object.
    * @param codeReader: to get the next token
    * @return ifCommand *
    */
    virtual Command *create(CodeReader &codeReader);
    /**
     * destructor, free memory
     */
    virtual ~IfCommandGenerator();


};

#endif
