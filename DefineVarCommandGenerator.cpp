//
// Created by ranraboh on 16/12/18.
//

#include "DefineVarCommandGenerator.h"
#include "DefineVarCommand.h"

Command *DefineVarCommandGenerator::create(CodeReader &codeReader) {
    string var = codeReader.getNextToken();
    if (codeReader.getNextToken() != "=")
        throw "syntax error: missing operator '='";
    if (codeReader.getNextToken() != "bind")
        throw "sytax error: missing bind keyword";
    string path = codeReader.getNextToken();
    return new DefineVarCommand(var, path, codeReader.getSymbolTable());
}
