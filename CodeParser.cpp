#include "CodeParser.h"
#include "ConditionParser.h"
#include "PrintCommand.h"
#include "WhileCommand.h"
CodeParser::CodeParser(CodeReader codeReader) : codeReader(codeReader) {
    this->loadCommandMap();
}
CodeParser::CodeParser(vector<string> code) : codeReader(code) {
    this->loadCommandMap();
}
void CodeParser::parseCode() {
    while (!this->codeReader.isEndPoint()) {
        this->parseNext();
    }
}
void CodeParser::loadCommandMap() {
    PrintCommand * printCommand = new PrintCommand;
    WhileCommand * whileCommand = new WhileCommand;
    this->commands["print"] = printCommand;
    this->commands["while"] = whileCommand;
}
void CodeParser::parseNext() {
    //loop trough all the command in the string array
    string codeToken = codeReader.getNextToken();
    Command * command = this->getCommand(codeToken);
    ConditionParser* conditionParser = dynamic_cast<ConditionParser*>(command);
    if (conditionParser != nullptr)
         this->parseBlock(*conditionParser);
    else
        command->execute(this->codeReader);
}

void CodeParser::parseBlock(ConditionParser & conditionParser) {
    list<Command *> blockCommands;
    string codeToken;
    string condition = this->codeReader.getNextToken();      // condition
    this->codeReader.getNextToken();
    CodeReader blockReader = codeReader.getEntireBlock();
    conditionParser.execute(blockReader);
    /*while (!blockReader.isEndPoint()) {
        codeToken = blockReader.getNextToken();
        Command *command = this->getCommand(codeToken);
        blockCommands.push_back(command);
    }
    conditiconParser.setCommandsList(blockCommands); */
}
Command* CodeParser::getCommand(string keyword) {
    map< string, Command * >::iterator iterator;
    iterator = this->commands.find(keyword);
    if (iterator == this->commands.end())
        throw "command not found";
    return iterator->second;
}
void CodeParser::begin() {
    this->codeReader.setIndex(0);
}
