#include "WhileCommandGenerator.h"
#include "ConditionParserGenerator.h"
/**
 * default constructor
 */
WhileCommandGenerator::WhileCommandGenerator() {
}

/**
 * constructor
 * @param codeParser
 */
 //todo: I dont understand what the codeParser is doing here, anyway we're not using it.
WhileCommandGenerator::WhileCommandGenerator(CodeParser *codeParser) {
    this->setCodeParser(codeParser);
}

/**
 * this function crate the while command
 * @param codeReader: to get the next token
 * @return whileCommand*
 */
Command* WhileCommandGenerator::create(CodeReader &codeReader) {
    ExpressionParser expressionParser(codeReader.getSymbolTable());
    string leftExpression = codeReader.getNextToken();
    string relation = codeReader.getNextToken();
    string rightExpression = codeReader.getNextToken();
    if (codeReader.getNextToken() != "{")
        throw INVALID_EXPRESSION;
    this->generateBlockCommands();
    WhileCommand* whileCommand = new WhileCommand(this->getBlockCommands(),expressionParser.parseExpression(rightExpression),
                                         expressionParser.parseExpression(leftExpression), relation);
    return  whileCommand;
}
