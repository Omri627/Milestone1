#include <iostream>
#include "PrintCommand.h"
#include "Var.h"

/**
 * constructor creates print command with the given variable and symbol-table
 * @param str the string to print
 */
PrintCommand::PrintCommand(string str) {
    this->str = str;
}

/**
 * constructor creates print command with the given variable and symbol-table
 * @param symbolTable symbolTable object
 * @param var the variable to print his value
 */
PrintCommand::PrintCommand(SymbolTable *symbolTable, string var) {
    this->symbolTable = symbolTable;
    this->str = var;
}
/**
 * prints out the messege or variable value on screen.
 * @return 1 if the operation finished successfully
 */
int PrintCommand::execute() {
    if (symbolTable != nullptr) {
        cout << to_string(symbolTable->getVar(this->str)->getValue()) << endl;
    } else {
        cout << str << endl;
    }
    return 1;
}