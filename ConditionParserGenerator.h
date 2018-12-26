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
    /**
     * creates condition parser generator object initialized with code parser.
     * @param codeParser code parser used to read commands in block
     */
    ConditionParserGenerator(CodeParser * codeParser);
    /**
     * setBlockCommands method sets the list of commands.
     * @param commands commands list in block
     */
    virtual void setBlockCommands(list<Command *> commands);
    /**
     * setCodeParser sets the code parser with given code parser object
     * @param parser code parser object
     */
    virtual void setCodeParser(CodeParser *parser);
    /**
     * generateBlockCommands method used parser to read
     * the block of commands from code.
     */
    virtual void generateBlockCommands();
    /**
     * destructor, free memory
     */
    virtual ~ConditionParserGenerator();
    /**
     * clear list of commands
     */
    virtual void clearBlockCommands();
    /**
     * getBlockCommands method return list of commands in block
     * @return return list of commands in block
     */
    virtual list<Command *> getBlockCommands();

};
#endif
