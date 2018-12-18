//
// Created by ranraboh on 16/12/18.
//

#ifndef PROJECT_OPENSERVERCOMMAND_H
#define PROJECT_OPENSERVERCOMMAND_H

#include "Command.h"

class OpenServerCommand : public Command {
private:

public:
    OpenServerCommand(CodeReader& codeReader);

    int execute();

};


#endif //PROJECT_OPENSERVERCOMMAND_H
