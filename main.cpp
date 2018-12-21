#include <iostream>
#include <string>
#include "ExpressionParser.h"
#include "Lexer.h"
#include "CodeParser.h"
#include "Utils.h"

using namespace std;
int main() {
    Lexer lexer;
    CodeParser *codeParser = new CodeParser(lexer);
    codeParser->runCode();
    exit(0);
    /*ExpressionParser expressionParser;
    SymbolTable symbolTable;
    expressionParser.setSymbolTable(symbolTable);
    symbolTable.addVariable("x", 3);
    symbolTable.addVariable("y", 5);
    symbolTable.addVariable("ran", 10);
    string expression = "3 * x + 2 * y";
    Expression * expObject = expressionParser.parseExpression(expression);
    double value = expObject->calculate();
    cout << value << endl;
    return 0; */
}