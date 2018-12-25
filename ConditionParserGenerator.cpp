#include "ConditionParserGenerator.h"
#include "CodeParser.h"
/**
 * empty constructor
 */
ConditionParserGenerator::ConditionParserGenerator() {

}
/**
 * the constructor creates condition parser generator initialized
 * with given code parser
 * @param codeParser code parser object
 */
ConditionParserGenerator::ConditionParserGenerator(CodeParser *codeParser) {
    this->codeParser = codeParser;
}
/**
 * setBlockCommands sets the list of commands
 * @param commands list of commands in block
 */
void ConditionParserGenerator::setBlockCommands(list<Command *> commands) {
    this->blockCommands = commands;
}
/**
 * clear list of block commands
 */
void ConditionParserGenerator::clearBlockCommands() {
    this->blockCommands.clear();
}
/**
 * getter method of block commands
 * @return returns the list of block commands
 */
list< Command* > ConditionParserGenerator::getBlockCommands() {
    return this->blockCommands;
}
/**
 * set the code parser object with given parser
 * @param parser code parser object
 */
void ConditionParserGenerator::setCodeParser(CodeParser *parser) {
    this->codeParser = parser;
}
/**
 * generateBlockCommands method used parser to read
 * the block of commands from code.
 */
void ConditionParserGenerator::generateBlockCommands() {
    this->blockCommands = this->codeParser->parseBlock();
}
/**
 * getBlockCommands method return list of commands in block
 * @return return list of commands in block
 */
ConditionParserGenerator::~ConditionParserGenerator() {
    /**for (Command * command : this->blockCommands) {
        delete command;
    }**/
}
