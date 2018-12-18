#include <iostream>
#include "PrintCommand.h"

PrintCommand::PrintCommand(string str) {
    this->str = str.substr(1, str.size() - 2);
}
int PrintCommand::execute() {
    cout << str << endl;
}