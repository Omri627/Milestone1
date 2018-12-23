#include "CodeParser.h"
#include "ConditionParser.h"
#include "PrintCommand.h"
#include "WhileCommand.h"
#include "IfCommandGenerator.h"
#include "OpenServerCommandGenerator.h"
#include "ConnectCommand.h"
#include "ConnectCommandGenerator.h"
#include "SleepCommandGenerator.h"
CodeParser::CodeParser(CodeReader* codeReader) {
    this->codeReader = codeReader;
    this->threadManager = new ThreadManager;
    this->loadCommandMap();
}
CodeParser::CodeParser(Lexer lexer) {
    this->codeReader = new CodeReader(lexer);
    this->threadManager = new ThreadManager;
    this->loadCommandMap();
}
CodeParser::CodeParser(Lexer lexer, ThreadManager *threadManager) {
    this->codeReader = new CodeReader(lexer);
    this->threadManager = threadManager;
    this->loadCommandMap();
}
void CodeParser::runCode() {
    Command * command;
    while (!this->codeReader->isEndPoint()) {
        command = this->parseNext();
        command->execute();
    }
}
void CodeParser::loadCommandMap() {
    PrintCommandGenerator* printGenerator = new PrintCommandGenerator;
    DefineVarCommandGenerator* defineGenerator = new DefineVarCommandGenerator;
    UpdateVarCommandGenerator* updateVarCommandGenerator = new UpdateVarCommandGenerator(this->clientServer);
    WhileCommandGenerator* whileGenerator = new WhileCommandGenerator;
    whileGenerator->setCodeParser(this);
    IfCommandGenerator* ifGenerator = new IfCommandGenerator;
    ifGenerator->setCodeParser(this);
    OpenServerCommandGenerator* serverCommandGenerator = new OpenServerCommandGenerator(this->threadManager);
    ConnectCommandGenerator* connectCommandGenerator = new ConnectCommandGenerator(this, this->threadManager);
    SleepCommandGenerator * sleepCommandGenerator = new SleepCommandGenerator;
    this->commands["print"] = printGenerator;
    this->commands["var"] = defineGenerator;
    this->commands["update"] = updateVarCommandGenerator;
    this->commands["if"] = ifGenerator;
    this->commands["while"] = whileGenerator;
    this->commands["openDataServer"] = serverCommandGenerator;
    this->commands["connect"] = connectCommandGenerator;
    this->commands["sleep"] = sleepCommandGenerator;
}
Command* CodeParser::parseNext() {
    //loop trough all the command in the string array
    string codeToken = codeReader->getNextToken();
    CommandGenerator * commandGenerator = this->getCommand(codeToken);
    Command * command = commandGenerator->create(*codeReader);
    return command;
}

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
void CodeParser::setClientServer(ClientServer *server) {
    this->clientServer = server;
}
CodeReader *CodeParser::getCodeReader() const {
    return codeReader;
}