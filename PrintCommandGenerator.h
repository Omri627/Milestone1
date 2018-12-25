#include "Command.h"

#ifndef PRINT_COMMAND_GENERATOR
    #define PRINT_COMMAND_GENERATOR
using namespace std;
#include "CommandGenerator.h"
#include "PrintCommand.h"
class PrintCommandGenerator : public CommandGenerator {
public:
    /**
     * create print command object.
     * @param codeReader: codeReader so create can get his params
     * @return new Command
     */
    virtual Command * create(CodeReader& codeReader);

    virtual ~PrintCommandGenerator();
};
#endif