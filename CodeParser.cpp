#include "CodeParser.h"
#include "ConditionParser.h"
#include "PrintCommand.h"
#include "WhileCommand.h"
#include "IfCommandGenerator.h"
#include "OpenServerCommandGenerator.h"
#include "ConnectCommand.h"
#include "ConnectCommandGenerator.h"
#include "SleepCommandGenerator.h"
#include "ExitCommandGenerator.h"
/**
 * creates code parser object initialized with code reader.
 * @param codeReader code tokens
 */
CodeParser::CodeParser(CodeReader* codeReader) {
    this->codeReader = codeReader;
    this->threadManager = new ThreadManager;
    this->loadCommandMap();
}
/**
 * creates code parser object initialized with code reader.
 * @param lexer code tokens generator
 */
CodeParser::CodeParser(Lexer lexer) {
    this->codeReader = new CodeReader(lexer);
    this->threadManager = new ThreadManager;
    this->loadCommandMap();
}
/**
 * creates code parser object initialized with code reader.
 * @param lexer code tokens generator
 */
CodeParser::CodeParser(Lexer lexer, ThreadManager *threadManager) {
    this->codeReader = new CodeReader(lexer);
    this->threadManager = threadManager;
    this->loadCommandMap();
}
/**
 * run the code line by line.
 * for each line parse the command and its parameters and execute his operation.
 */
void CodeParser::runCode() {
    Command * command;
    while (!this->codeReader->isEndPoint()) {
        command = this->parseNext();
        command->execute();
        delete command;
    }
}
/**
 * loads the commands generator map.
 * used for creating new commands in code.
 * inserts all types of generators of commands that exists in code.
 */
void CodeParser::loadCommandMap() {
    PrintCommandGenerator* printGenerator = new PrintCommandGenerator;
    DefineVarCommandGenerator* defineGenerator = new DefineVarCommandGenerator;
    UpdateVarCommandGenerator* updateVarCommandGenerator = new UpdateVarCommandGenerator(this->clientServer);
    WhileCommandGenerator* whileGenerator = new WhileCommandGenerator(this);
    IfCommandGenerator* ifGenerator = new IfCommandGenerator(this);
    OpenServerCommandGenerator* serverCommandGenerator = new OpenServerCommandGenerator(this->threadManager);
    ConnectCommandGenerator* connectCommandGenerator = new ConnectCommandGenerator(this, this->threadManager);
    SleepCommandGenerator * sleepCommandGenerator = new SleepCommandGenerator;
    ExitCommandGenerator * exitCommandGenerator = new ExitCommandGenerator(this, this->threadManager, this->clientServer);
    this->commands["print"] = printGenerator;
    this->commands["var"] = defineGenerator;
    this->commands["update"] = updateVarCommandGenerator;
    this->commands["if"] = ifGenerator;
    this->commands["while"] = whileGenerator;
    this->commands["openDataServer"] = serverCommandGenerator;
    this->commands["connect"] = connectCommandGenerator;
    this->commands["sleep"] = sleepCommandGenerator;
    this->commands["exit"] = exitCommandGenerator;
}
/**
 * parse next line in code.
 * the method reads the line, seperates the parameters
 * and generate new command with the given arguments.
 * @return returns new command object corresponding the next command in code.
 */
Command* CodeParser::parseNext() {
    //loop trough all the command in the string array
    string codeToken = codeReader->getNextToken();
    CommandGenerator * commandGenerator = this->getCommand(codeToken);
    Command * command = commandGenerator->create(*codeReader);
    return command;
}
/**
 * parseBlock method parse the code in entire block.
 * run through lines in block, parse each commands and its parameters
 * @return returns list of the commands in block
 */
list< Command* > CodeParser::parseBlock() {
    list<Command *> blockCommands;
    string codeToken;
    while (!this->codeReader->isBlockEnd()) {
        Command * command = this->parseNext();
        blockCommands.push_back(command);
    }
    this->codeReader->getNextToken();          // ignore end of block '}'
    return blockCommands;
}
/**
 * getCommand method gets a keyword which signify command type
 * returns the command generator of the same type,
 * @param keyword type of command
 * @return command generator of the same type
 */
CommandGenerator* CodeParser::getCommand(string keyword) {
    map< string, CommandGenerator * >::iterator iterator;
    iterator = this->commands.find(keyword);
    if (iterator == this->commands.end()) {
        if (!this->codeReader->getSymbolTable()->isVariableExist(keyword))
            throw "command not found";
        return this->commands["update"];
    }
    return iterator->second;
}
/**
 * setClientServer method sets the server of simulator
 * @param server client server object
 */
void CodeParser::setClientServer(ClientServer *server) {
    this->clientServer = server;
    delete this->commands["update"];
    this->commands["update"] = new UpdateVarCommandGenerator(server);
}
/**
 * getter method of code reader field
 * @return returns the code reader (=code tokens) object
 */
CodeReader *CodeParser::getCodeReader() const {
    return codeReader;
}
/**
 * destructor, free memory
 */
CodeParser::~CodeParser() {
    map < string, CommandGenerator* >::iterator iterator;
    iterator = this->commands.begin();
    while (iterator != this->commands.end()) {
        delete iterator->second;
        iterator++;
    }
    delete this->codeReader;
}
