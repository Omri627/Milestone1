#ifndef PROJECT_COMMANDGENERATOR_H
#define PROJECT_COMMANDGENERATOR_H


#include "CodeReader.h"
#include "Command.h"

class CommandGenerator {
public:
    /**
    * create method creates new command object
    * the method reads the parameters for command from code tokens
    * @param codeReader code tokens
    * @return command object
    */
    virtual Command *create(CodeReader &codeReader) = 0;

    /**
    * destructor, free memory
    */
    virtual ~CommandGenerator();
};


#endif
