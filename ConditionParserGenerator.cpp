#include "ConditionParserGenerator.h"
ConditionParserGenerator::ConditionParserGenerator() {

}
void ConditionParserGenerator::setBlockCommands(list<Command *> commands) {
    this->blockCommands = commands;
}
void ConditionParserGenerator::clearBlockCommands() {
    this->blockCommands.clear();
}
list< Command* > ConditionParserGenerator::getBlockCommands() {
    return this->blockCommands;
}
void ConditionParserGenerator::setCodeParser(CodeParser *parser) {
    this->codeParser = parser;
}
void ConditionParserGenerator::generateBlockCommands() {
    this->blockCommands = this->codeParser->parseBlock();
}
