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
     * remove the One size boolean operator from the end of the string and remove excess spaces
     * @param s string by reference
     * @return the operator
     */
    string extractOneOperator(string &s);

    /**
     * remove the Two size boolean operator from the end of the string and remove excess spaces
     * @param s string by reference
     * @return the operator
     */
    string extractTwoOperator(string &s);

    /**
     * check if the line contain boolean operator of size 2
     * @param line string line to check
     * @param i the index to check from
     * @return true if contains, else false
     */
    bool isContainBoolTwoOperators(string line, int i);

        /**
        * check if the line contain boolean operator of size 1
        * @param line string line to check
        * @param i the index to check from
        * @return true if contains, else false
        */
    bool isContainOneBoolOperator(string line, int i);

    /**
     * get the rest of the line from given index and remove excess spacess
     * @param line string
     * @param i the index to get the rest of the line
     * @return string- the rest of the line
     */
    string getRestFromIndex(string line, int i);
public:
    /**
     * get vector of string that represent expressions from file
     * @param filename
     * @return vector<string>
     */
    vector<string> getSplitFromFile(string filename);

};

#endif
