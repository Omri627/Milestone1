#ifndef LEXER
    #define LEXER

#include <string>
#include <vector>
#include <regex>

using namespace std;
class Lexer {
private:
    vector<string> codeLine;

    /**
     * trim excess spaces
     * @param s string
     * @return the string withoutexcess spaces
     */
    string trimSpaces(string s);
    /**
     * extract one expression at the time from string line
     * @param line string that reprsant one line of the script
     * @param i the current position of the line looping
     * @return one string that got extracted from line by order
     */
    string getOneExpression(string line, int& i);
    /**
     * check if the char is operator
     * @param c the char to be checked
     * @return true if char is operator, false otherwise
     */
    bool isCharOperator(char c);
    /**
     * remove the = from the end of the string and remove excess spaces
     * @param s string by refernce
     */
    string extractOneOperator(string &s);

    string extractTwoOperator(string &s);

    bool isContainBoolTwoOperators(string line, int i);

    bool isContainOneBoolOperator(string line, int i);
public:
    /**
     * get vector of string that represent expressions from file
     * @param filename
     * @return vector<string>
     */
    vector<string> getSplitFromFile(string filename);

};

#endif
