#include "ConditionParserGenerator.h"
ConditionParserGenerator::ConditionParserGenerator() {

}
ConditionParserGenerator::ConditionParserGenerator(list<Command *> blockCommands) {
    this->blockCommands = blockCommands;
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