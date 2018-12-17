#ifndef LEXER
    #define LEXER

#include <string>
#include <vector>
using namespace std;
class Lexer {
private:
    vector<string> codeLine;
public:
    vector<string> getSplitFromFile();

    string trimSpaces(string s);
};

#endif
