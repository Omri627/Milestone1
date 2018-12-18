#ifndef CODE_PAESER
    #define CODE_PARSER
#include <string>
#include <map>
#include "Command.h"
#include "CodeReader.h"
#include "ConditionParser.h"
#include "DefineVarCommandGenerator.h"
#include "PrintCommandGenerator.h"
#include "CommandGenerator.h"
#include "UpdateVarCommandGenerator.h"
#include "ConditionParserGenerator.h"
using namespace std;

class CodeParser {
private:
    CodeReader* codeReader;          //the code reader will handle the parameter for each command

    map<string, CommandGenerator*> commands;
public:

    CodeParser(CodeReader* codeReader);

    CodeParser(Lexer lexer);

    void loadCommandMap();

    void parseNext();

    void parseCode();

    void parseBlock(ConditionParser & conditionParser);

    CommandGenerator* getCommand(string keyword);

};


#endif