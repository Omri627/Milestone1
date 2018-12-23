
#include "IfCommandGenerator.h"
/**
 * default constructor
 */
IfCommandGenerator::IfCommandGenerator() {

}

//todo: I dont understand what the codeParser is doing here, anyway we're not using it. 2
IfCommandGenerator::IfCommandGenerator(CodeParser *codeParser) {
    this->setCodeParser(codeParser);
}

/**
 * this function crate the if command
 * @param codeReader: to get the next token
 * @return ifCommand*
 */
Command* IfCommandGenerator::create(CodeReader &codeReader) {
    ExpressionParser expressionParser(codeReader.getSymbolTable());
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
