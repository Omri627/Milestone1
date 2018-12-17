//
// Created by ranraboh on 16/12/18.
//

#include "UpdateVarCommandGenerator.h"
#include "ExpressionParser.h"
#include "UpdateVarCommand.h"

Command *UpdateVarCommandGenerator::create(CodeReader &codeReader) {
    ExpressionParser expressionParser;
    string var =  codeReader.getPreviousToken();             // get name of variable which we skipped
    if (codeReader.getNextToken() != "=")
        throw "syntax error: missing operator '='";
    string expression = codeReader.getNextToken();           // get expression
    return new UpdateVarCommand(var, expressionParser.parseExpression(expression), codeReader.getSymbolTable());
}
