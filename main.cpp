#include <iostream>
#include <string>
#include "ExpressionParser.h"
#include "Lexer.h"
#include "CodeParser.h"

using namespace std;
int main() {
    vector<string> strVec;
    Lexer lexer;
    strVec = lexer.getSplitFromFile("script.txt");
    for (string s : strVec) {
        cout << "|" << s;

    }
    //CodeParser *codeParser = new CodeParser(lexer);
    //codeParser->parseCode();
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