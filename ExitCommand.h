#include "Command.h"
#include "CodeParser.h"

#ifndef EXIT_COMMAND
    #define EXIT_COMMAND

class ExitCommand : public Command {
private:
    CodeParser * codeParser;
    ClientServer * clientServer;
    ThreadManager * threadManager;
public:
    /**
    * creates Exit Command object initialized with given code parser
    * @param codeParser code parser object
    */
    ExitCommand(CodeParser *codeParser, ThreadManager * threadManager, ClientServer * clientServer);
    /**
     *
     * @return
     */
    virtual int execute();

    virtual ~ExitCommand();

};


#endif