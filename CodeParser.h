#ifndef CODE_PAESER
    #define CODE_PAESER
#include <string>
#include <map>
#include "Command.h"
#include "CodeReader.h"
#include "ConditionParser.h"
#include "DefineVarCommandGenerator.h"
#include "PrintCommandGenerator.h"
#include "CommandGenerator.h"
#include "UpdateVarCommandGenerator.h"
#include "ConditionParserGenerator.h"
#include "WhileCommandGenerator.h"
using namespace std;
class IfCommandGenerator;
class CodeParser {
private:
    CodeReader* codeReader;          //the code reader will handle the parameter for each command

    map<string, CommandGenerator*> commands;

    WhileCommandGenerator* whileCommand;

    IfCommandGenerator* ifCommand;
public:

    CodeParser(CodeReader* codeReader);

    CodeParser(Lexer lexer);

    void loadCommandMap();

    Command* parseNext();

    void runCode();

    list < Command* > parseBlock();

    CommandGenerator* getCommand(string keyword);

    CodeReader *getCodeReader() const;

};


#endif