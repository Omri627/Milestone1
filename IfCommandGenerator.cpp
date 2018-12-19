#include "IfCommandGenerator.h"

IfCommandGenerator::IfCommandGenerator() {
}
IfCommandGenerator::IfCommandGenerator(list<Command *> commands) : ConditionParserGenerator(commands) {
}
Command* IfCommandGenerator::create(CodeReader &codeReader) {
    ExpressionParser expressionParser(codeReader.getSymbolTable());
    string leftExpression = codeReader.getNextToken();
    string relation = codeReader.getNextToken();
    string rightExpression = codeReader.getNextToken();
    if (codeReader.getNextToken() != "{")
        throw "invalid expression";
    IfCommand* ifCommand = new IfCommand(expressionParser.parseExpression(rightExpression),
            expressionParser.parseExpression(leftExpression), relation);
    return ifCommand;
}
