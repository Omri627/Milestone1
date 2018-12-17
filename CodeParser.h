#ifndef CODE_PAESER
    #define CODE_PARSER
#include <string>
#include <map>
#include "Command.h"
#include "CodeReader.h"
#include "ConditionParser.h"
using namespace std;

class CodeParser {
private:
    CodeReader codeReader;          //the code reader will handle the parameter for each command

    map<string, Command*> commands;
public:

    CodeParser(CodeReader codeReader);

    CodeParser(vector<string> code);

    void loadCommandMap();

    void parseNext();

    void parseCode();

    void parseBlock(ConditionParser & conditionParser);

    Command* getCommand(string keyword);

    void begin();
};


#endif