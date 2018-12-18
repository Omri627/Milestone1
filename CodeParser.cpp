#include "CodeParser.h"
#include "ConditionParser.h"
#include "PrintCommand.h"
#include "WhileCommand.h"
CodeParser::CodeParser(CodeReader* codeReader) {
    this->codeReader = codeReader;
    this->loadCommandMap();
}
CodeParser::CodeParser(Lexer lexer) {
    this->codeReader = new CodeReader(lexer);
    this->loadCommandMap();
}
void CodeParser::parseCode() {
    while (!this->codeReader->isEndPoint()) {
        this->parseNext();
    }
}
void CodeParser::loadCommandMap() {
    PrintCommandGenerator* printGenerator = new PrintCommandGenerator;
    this->commands["print"] = printGenerator;
}
void CodeParser::parseNext() {
    //loop trough all the command in the string array
    string codeToken = codeReader->getNextToken();
    CommandGenerator * commandGenerator = this->getCommand(codeToken);
    Command * command = commandGenerator->create(*codeReader);
    command->execute();
}

void CodeParser::parseBlock(ConditionParser & conditionParser) {
    /*list<Command *> blockCommands;
    string codeToken;
    string condition = this->codeReader.getNextToken();      // condition
    this->codeReader.getNextToken();
    CodeReader blockReader = codeReader.getEntireBlock();
    conditionParser.execute(blockReader);
    while (!blockReader.isEndPoint()) {
        codeToken = blockReader.getNextToken();
        Command *command = this->getCommand(codeToken);
        blockCommands.push_back(command);
    }
    conditiconParser.setCommandsList(blockCommands); */
}
CommandGenerator* CodeParser::getCommand(string keyword) {
    map< string, CommandGenerator * >::iterator iterator;
    iterator = this->commands.find(keyword);
    if (iterator == this->commands.end())
        throw "command not found";
    return iterator->second;
}