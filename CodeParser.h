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
#include "ClientServer.h"
#include "ThreadManager.h"
using namespace std;
class IfCommandGenerator;
class CodeParser {
private:
    CodeReader* codeReader;          //the code reader will handle the parameter for each command

    map<string, CommandGenerator*> commands;

    ClientServer * clientServer;

    ThreadManager * threadManager;
public:
    CodeParser(CodeReader* codeReader);

    CodeParser(Lexer lexer);

    CodeParser(Lexer lexer, ThreadManager * threadManager);

    void loadCommandMap();

    Command* parseNext();

    void runCode();

    list < Command* > parseBlock();

    CommandGenerator* getCommand(string keyword);

    void setClientServer(ClientServer * server);

    CodeReader *getCodeReader() const;

};


#endif