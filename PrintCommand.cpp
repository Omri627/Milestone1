#include <iostream>
#include "PrintCommand.h"
#include "Var.h"
#include "ExpressionParser.h"

/**
* constructor: creates print command object initialized with given string.
* the created command will print out the string on screen
* @param str the string to print
*/
PrintCommand::PrintCommand(string str) {
    this->str = str;
    this->symbolTable = nullptr;
}

/**
* constructor: creates print command object initialized with given variable name and symbol table object.
* the created command will print out the value of given variable on screen
* @param symbolTable symbol table object
* @param var the var to print his value
*/
PrintCommand::PrintCommand(SymbolTable *symbolTable, string expression) {
    this->symbolTable = symbolTable;
    this->str = expression;
}

/**
 * prints out the messege or variable value on screen.
 * @return 1 if the operation finished successfully
 */
int PrintCommand::execute() {
    if (symbolTable != nullptr) {
        try {
            ExpressionParser * parser = new ExpressionParser(this->symbolTable);
            Expression * expression = parser->parseExpression(this->str);
            cout << to_string(expression->calculate()) << endl;
        } catch (const char* message) {
            cout << message << endl;
            exit(1);
        }
    } else {
        cout << str << endl;
    }
    return 1;
}

PrintCommand::~PrintCommand() {};
