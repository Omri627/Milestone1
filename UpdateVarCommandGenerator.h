#ifndef DEFINE_VAR_COMMAND_CREATOR
    #define DEFINE_VAR_COMMAND_CREATOR

#include "CommandGenerator.h"
#include "Var.h"
#include "DataServer.h"

class UpdateVarCommandGenerator : public CommandGenerator {
private:
    /* simulator server (= used in order to update the variables in server) */
    ClientServer * server;
public:
/**
 * the constructor creates generator object which used to create update-var commands
 * @param server simulator server
 */
    UpdateVarCommandGenerator(ClientServer * server);

    /**
     * create method creates new command object of updateVar type.
     * this commands used to update variables value.
     * if simulator server is connected and the variable is bound.
     * then the method updates the simulator.
     * @param codeReader code tokens
     * @return returns update var command object.
     */
    Command *create(CodeReader &codeReader);
    /**
     * destructor, free memory
     */
    ~UpdateVarCommandGenerator();
};


#endif //PROJECT_DEFINEVARCOMMANDCREATOR_H
