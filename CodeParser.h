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
    /* code tokens */
    CodeReader* codeReader;
    /* list of all commands generators */
    map<string, CommandGenerator*> commands;
    /* client server object */
    ClientServer * clientServer;
    /* thread manager object */
    ThreadManager * threadManager;
public:
    /**
     * creates code parser object initialized with code reader.
     * @param codeReader code tokens
     */
    CodeParser(CodeReader* codeReader);
    /**
     * creates code parser object initialized with code reader.
     * @param lexer code tokens generator
     */
    CodeParser(Lexer lexer);
    /**
     * creates code parser object initialized with code reader.
     * @param lexer code tokens generator
     */
    CodeParser(Lexer lexer, ThreadManager * threadManager);
    /**
     * loads the commands generator map.
     * used for creating new commands in code.
     * inserts all types of generators of commands that exists in code.
     */
    void loadCommandMap();
    /**
     * parse next line in code.
     * the method reads the line, seperates the parameters
     * and generate new command with the given arguments.
     * @return returns new command object corresponding the next command in code.
     */
    Command* parseNext();
    /**
     * run the code line by line.
     * for each line parse the command and its parameters and execute his operation.
     */
    void runCode();
    /**
     * parseBlock method parse the code in entire block.
     * run through lines in block, parse each commands and its parameters
     * @return returns list of the commands in block
     */
    list < Command* > parseBlock();
    /**
     * getCommand method gets a keyword which signify command type
     * returns the command generator of the same type,
     * @param keyword type of command
     * @return command generator of the same type
     */
    CommandGenerator* getCommand(string keyword);
    /**
     * setClientServer method sets the server of simulator
     * @param server client server object
     */
    void setClientServer(ClientServer * server);
    /**
     * getter method of code reader field
     * @return returns the code reader (=code tokens) object
     */
    CodeReader *getCodeReader() const;
    /**
     * destructor, free memory
     */
    virtual ~CodeParser();

};


#endif