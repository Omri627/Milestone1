
#include "IfCommandGenerator.h"
/**
 * default constructor
 */
IfCommandGenerator::IfCommandGenerator() {

}
/**
 * creates If Command generator object initialized with code parser.
 * @param codeParser code parser object
 */
IfCommandGenerator::IfCommandGenerator(CodeParser *codeParser)
: ConditionParserGenerator(codeParser) {

}
/**
* create method creates if command object.
* @param codeReader: to get the next token
* @return ifCommand *
*/
Command* IfCommandGenerator::create(CodeReader &codeReader) {
    ExpressionParser expressionParser(codeReader.getSymbolTable());
    const int commandParameters = 5;
    /* throw exception in case no enough parameters was given */
    if (!codeReader.isRemainingToken(commandParameters))
        throw "invalid if command";
    string leftExpression = codeReader.getNextToken();
    string relation = codeReader.getNextToken();
    string rightExpression = codeReader.getNextToken();
    if (codeReader.getNextToken() != "{")
        throw INVALID_EXPRESSION;
    this->generateBlockCommands();
    IfCommand *ifCommand = new IfCommand(this->getBlockCommands(),
                                         expressionParser.parseExpression(rightExpression),
                                         expressionParser.parseExpression(leftExpression), relation);
    return ifCommand;
}
/**
* destructor, free memory
*/
IfCommandGenerator::~IfCommandGenerator() {
}
