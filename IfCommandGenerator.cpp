
#include "IfCommandGenerator.h"
/**
 * default constructor
 */
IfCommandGenerator::IfCommandGenerator() {

}

IfCommandGenerator::IfCommandGenerator(CodeParser *codeParser)
: ConditionParserGenerator(codeParser) {

}

/**
 * this function crate the if command
 * @param codeReader: to get the next token
 * @return ifCommand*
 */
Command* IfCommandGenerator::create(CodeReader &codeReader) {
    ExpressionParser expressionParser(codeReader.getSymbolTable());
    const int commandParameters = 5;
    /* throw exception in case no enough parameters was given */
    if (!codeReader.isRemainingToken(commandParameters))
        throw "invalid open server command: no enough parameters transmitted";
    string leftExpression = codeReader.getNextToken();
    string relation = codeReader.getNextToken();
    string rightExpression = codeReader.getNextToken();
    if (codeReader.getNextToken() != "{")
        throw INVALID_EXPRESSION;
    this->generateBlockCommands();
    IfCommand* ifCommand = new IfCommand(this->getBlockCommands(), expressionParser.parseExpression(rightExpression),
                                         expressionParser.parseExpression(leftExpression), relation);
    return ifCommand;
}
IfCommandGenerator::~IfCommandGenerator() {
}
