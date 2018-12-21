#include <iostream>
#include "PrintCommand.h"
#include "Var.h"

PrintCommand::PrintCommand(string str) {
    this->str = str;
}

int PrintCommand::execute() {
    cout << str << endl;
}