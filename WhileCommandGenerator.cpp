#include "WhileCommandGenerator.h"
#include "ConditionParserGenerator.h"
/**
 * default constructor
 */
WhileCommandGenerator::WhileCommandGenerator() {
}
/**
 * creates WhileCommandGenerator object with given code parser.
 * the code parser used to read the commands in block.
 * @param codeParser code parser object
 */
WhileCommandGenerator::WhileCommandGenerator(CodeParser *codeParser)
: ConditionParserGenerator(codeParser) {
}
/**
 * this function crate the while command
 * @param codeReader: to get the next token
 * @return whileCommand*
 */
Command* WhileCommandGenerator::create(CodeReader &codeReader) {
    ExpressionParser expressionParser(codeReader.getSymbolTable());
    const int commandParameters = 5;
    /* throw exception in case no enough parameters was given */
    if (!codeReader.isRemainingToken(commandParameters))
        throw "invalid while command";
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
WhileCommandGenerator::~WhileCommandGenerator() {}
