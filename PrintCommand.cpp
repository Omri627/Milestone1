#include <iostream>
#include "PrintCommand.h"
#include "Var.h"

/**
 * constructor
 * @param str the string to print
 */
PrintCommand::PrintCommand(string str) {
    this->str = str;
}

/**
 * constructor
 * @param symbolTable symbolTable
 * @param var the var to print his value
 */
PrintCommand::PrintCommand(SymbolTable *symbolTable, string var) {
    this->symbolTable = symbolTable;
    this->str = var;
}
/**
 * preform print command
 * @return int
 */
int PrintCommand::execute() {
    if (symbolTable != nullptr) {
        cout << to_string(symbolTable->getVar(this->str)->getValue()) << endl;
    } else {
        cout << str << endl;
    }
}