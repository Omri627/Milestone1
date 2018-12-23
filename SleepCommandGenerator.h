#ifndef SLEEP_COMMAND_GENERATOR
    #define SLEEP_COMMAND_GENERATOR

#include "Command.h"
#include "SleepCommand.h"
#include "CommandGenerator.h"
class SleepCommandGenerator : public CommandGenerator {
public:
    /**
     * reads the parameter from the code script
     * and creates a sleep command with the given parameter
     * @param codeReader holds the code tokens
     * @return returns sleep command object
     */
    Command *create(CodeReader &codeReader) override;
};

#endif
