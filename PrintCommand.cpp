#include <iostream>
#include "PrintCommand.h"
#include "Var.h"

PrintCommand::PrintCommand(string str) {
    this->str = str;
}
PrintCommand::PrintCommand(SymbolTable *symbolTable, string var) {
    this->symbolTable = symbolTable;
    this->str = var;
}
int PrintCommand::execute() {
    if (symbolTable != nullptr) {
        cout << to_string(symbolTable->getVar(this->str)->getValue()) << endl;
    } else {
        cout << str << endl;
    }
}