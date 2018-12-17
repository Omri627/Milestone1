//
// Created by ranraboh on 16/12/18.
//

#ifndef PROJECT_DEFINEVARCOMMAND_H
#define PROJECT_DEFINEVARCOMMAND_H


#include "Command.h"

class DefineVarCommand : public Command {
private:
    string var;
    string path;
    SymbolTable& symbolTable;
public:
    DefineVarCommand(string var, string path,SymbolTable& symbolTable);

    int execute() override;
};


#endif //PROJECT_DEFINEVARCOMMAND_H
