#ifndef PROJECT_DEFINEVARCOMMANDCREATOR_H
#define PROJECT_DEFINEVARCOMMANDCREATOR_H


#include "CommandGenerator.h"
#include "Var.h"
#include "DataServer.h"

class UpdateVarCommandGenerator : public CommandGenerator {
private:
    ClientServer * server;
public:
    UpdateVarCommandGenerator(ClientServer * server);

    Command *create(CodeReader &codeReader);

};


#endif //PROJECT_DEFINEVARCOMMANDCREATOR_H
