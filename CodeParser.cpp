#include "CodeParser.h"
#include "ConditionParser.h"
#include "PrintCommand.h"
#include "WhileCommand.h"
#include "IfCommandGenerator.h"
CodeParser::CodeParser(CodeReader* codeReader) {
    this->codeReader = codeReader;
    this->loadCommandMap();
}
CodeParser::CodeParser(Lexer lexer) {
    this->codeReader = new CodeReader(lexer);
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
    UpdateVarCommandGenerator* updateVarCommandGenerator = new UpdateVarCommandGenerator;
    WhileCommandGenerator* whileGenerator = new WhileCommandGenerator;
    whileGenerator->setCodeParser(this);
    IfCommandGenerator* ifGenerator = new IfCommandGenerator;
    ifGenerator->setCodeParser(this);
    this->commands["print"] = printGenerator;
    this->commands["var"] = defineGenerator;
    this->commands["update"] = updateVarCommandGenerator;
    this->commands["if"] = ifGenerator;
    this->commands["while"] = whileGenerator;
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