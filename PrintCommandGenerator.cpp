#include "PrintCommandGenerator.h"
#include "Var.h"
Command* PrintCommandGenerator::create(CodeReader &codeReader) {
    string str = codeReader.getNextToken();
    if (str.find("\"") == string::npos) {
        //the string to print is var
        Var* var = codeReader.getSymbolTable()->getVar(str);
        if (var != nullptr)
            return new PrintCommand(to_string(var->getValue()));
    } else {
        str = str.substr(1, str.size() - 2);
        return new PrintCommand(str);
    }
    return new PrintCommand(str);
}