#include "DefineVarCommandGenerator.h"
#include "DefineVarBindCommand.h"

Command *DefineVarCommandGenerator::create(CodeReader &codeReader) {
    bool isBind = false;
    string var = codeReader.getNextToken();
    string expression;
    ExpressionParser expressionParser(codeReader.getSymbolTable());
    if (codeReader.getNextToken() != "=")
        throw "syntax error: missing operator '='";
    if (codeReader.peekNextToken() == "bind") {
        isBind = true;
        codeReader.getNextToken();
        string path = codeReader.getNextToken();
        return new DefineVarBindCommand(var, path, codeReader.getSymbolTable());
    }
    expression = codeReader.getNextToken();
    return new DefineVarCommand(var, expressionParser.parseExpression(expression), codeReader.getSymbolTable());
}
