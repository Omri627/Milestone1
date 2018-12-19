#include "WhileCommandGenerator.h"
#include "ConditionParserGenerator.h"

WhileCommandGenerator::WhileCommandGenerator() {
}
Command* WhileCommandGenerator::create(CodeReader &codeReader) {
    ExpressionParser expressionParser(codeReader.getSymbolTable());
    string leftExpression = codeReader.getNextToken();
    string relation = codeReader.getNextToken();
    string rightExpression = codeReader.getNextToken();
    if (codeReader.getNextToken() != "{")
        throw "invalid expression";
    this->generateBlockCommands();
    WhileCommand* ifCommand = new WhileCommand(this->getBlockCommands(),expressionParser.parseExpression(rightExpression),
                                         expressionParser.parseExpression(leftExpression), relation);
    return  ifCommand;
}
