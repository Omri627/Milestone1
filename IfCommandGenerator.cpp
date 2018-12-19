#include "IfCommandGenerator.h"

IfCommandGenerator::IfCommandGenerator() {
}
IfCommandGenerator::IfCommandGenerator(CodeParser * parser) : ConditionParserGenerator(parser) {
}
Command* IfCommandGenerator::create(CodeReader &codeReader) {
    ExpressionParser expressionParser(codeReader.getSymbolTable());
    string leftExpression = codeReader.getNextToken();
    string relation = codeReader.getNextToken();
    string rightExpression = codeReader.getNextToken();
    if (codeReader.getNextToken() != "{")
        throw "invalid expression";
    IfCommand* ifCommand = new IfCommand(this(), expressionParser.parseExpression(rightExpression),
            expressionParser.parseExpression(leftExpression), relation);
    return ifCommand;
}
