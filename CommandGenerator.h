#ifndef PROJECT_COMMANDGENERATOR_H
#define PROJECT_COMMANDGENERATOR_H


#include "CodeReader.h"
#include "Command.h"

class CommandGenerator {
public:
virtual Command * create(CodeReader& codeReader) = 0;
};


#endif
