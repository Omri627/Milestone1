#include <fstream>
#include <iostream>
#include "Lexer.h"
#define EQUAL "="
#define EQUAL "="
#define GRATER ">"
#define LESS "<"
#define LESS_EQUAL "<="
#define GRATER_EQUAL ">="
#define EQUAL_EQUAL "=="
#define NOT_EQUAL "!="
#define C_EQUAL '='
#define C_PLUS '+'
#define C_MINUS '-'
#define C_MUL '*'
#define C_DIV '/'
#define C_POW '^'
#define C_SPACE ' '
#define C_COMMA ','
#define C_GRATER '>'
#define C_LESS '<'
#define PRINT "print"
/**
* get vector of string that represent expressions from file
* @param filename
* @return vector<string>
*/
vector<string> Lexer::getSplitFromFile() {

    ifstream infile;
    infile.open(this->fileName, ios::in);
    if (!infile.is_open()) {
        throw "file did not opened";
    }
    string line;
    while (getline(infile, line)) {
        if (!line.empty()) {
            for (int i = 0; i < line.length(); i++) {
                string word = getOneExpression(line, i);
                word = trimSpaces(word);
                if (word == "") {
                    continue;
                } if (word == PRINT) {
                    codeLine.push_back(word);
                    i++;
                    //the next parameter is the rest of the word;
                    word = getRestFromIndex(line, i);
                    codeLine.push_back(word);
                    break;

                }else if (word.find(EQUAL) != string::npos || word.find(GRATER) != string::npos ||
                          word.find(LESS) != string::npos)  { //check if contains  = | < | >

                    if (word.find(NOT_EQUAL) != string::npos|| word.find(EQUAL_EQUAL) != string::npos||
                        word.find(GRATER_EQUAL) != string::npos|| word.find(LESS_EQUAL) != string::npos) {
                        //check if contains two boolean operators
                        string s = extractTwoOperator(word);
                        word = trimSpaces(word);
                        codeLine.push_back(word);
                        codeLine.push_back(s);

                    } else {
                        //one boolean operator
                        string s = extractOneOperator(word);
                        word = trimSpaces(word);
                        codeLine.push_back(word);
                        codeLine.push_back(s);
                        if (s == EQUAL) {
                            if (line.find("bind") == string::npos) {
                                string s2 = line.substr(i + 1);
                                codeLine.push_back(s2);
                                break;
                            }
                        }
                    }

                } else {
                    codeLine.push_back(word);
                }
            }
        }
    }
    infile.close();
    return codeLine;
}
/**
* trim excess spaces
* @param s string
* @return the string withoutexcess spaces
*/
string Lexer::trimSpaces(string s) {
    int start = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == C_SPACE){
            start++;
        } else {
            break;
        }
    }
    int count = 0;
    for (int i = s.length() - 1; i > 0; i--) {
        if (s[i] == C_SPACE){
            count++;
        } else {
            break;
        }
    }
    s = s.substr(start, s.length() - start - count);
    return s;
}
/**
* extract one expression at the time from string line
* @param line string that reprsant one line of the script
* @param i the current position of the line looping
* @return one string that got extracted from line by order
*/
string Lexer::getOneExpression(string line, int &i) {
    int temp = i;
    bool isSign = false;
    bool isSpaceBefore = false;
    bool isBreak = false;
    int endIndex = i;

    for (i; i < line.length(); i++) {
        //loop through line

        if (isContainBoolTwoOperators(line, i)) {
            //found Two boolean operators
            i++;
            endIndex = i;
            isBreak = false;
            break;
        }

        if (line[i] == C_EQUAL || isContainOneBoolOperator(line, i)) {
            endIndex = i;
            isBreak = false;
            break;
        }

        if (line[i] == C_COMMA){
            endIndex = i;
            isBreak = true;
            break;
        }

        if (isCharOperator(line[i])) {
            isSign = true;
            isSpaceBefore = false;
            continue; //skip the char and continue
        }

        if (line[i] != C_SPACE && !isCharOperator(line[i])) { //the char is not a space or operator

            if (isSpaceBefore) {
                if (isSign) {
                    endIndex = i; // valid expression
                    isSign = false;//we use the sign
                    isSpaceBefore = false;
                    continue;
                } else {
                    i--; //minus 1 the index back because the next parm is start there
                    isBreak = true;
                    break; //the rest of the line can't be first parameter
                }
            }
            isSpaceBefore = false;
            endIndex = i;
            continue;
        }
        //the char is space
        isSpaceBefore = true;
        endIndex = i;
    }
    if (!isBreak) //if there was not break, the endIndex should promoted by 1
        endIndex += 1;
    string word = line.substr(temp,endIndex - temp);
    return  word;
}

/**
* check if the char is operator
* @param c the char to be checked
* @return true if char is operator, false otherwise
*/
bool Lexer::isCharOperator(char c) {
    char operators[]  = {C_DIV, C_MUL, C_MINUS, C_PLUS, C_POW};

    for (int j = 0; j < sizeof(operators)/ sizeof(*operators); j++) {
        //loop though the operators
        if (c == operators[j]) {
            return true;
        }
    }
    return  false;
}
/**
* remove the One size boolean operator from the end of the string and remove excess spaces
* @param s string by reference
* @return the operator
*/
string Lexer::extractOneOperator(string &s) {
    string res = "";
    res += s[s.length()-1];
    s = s.substr(0,s.length()-1); //remove the equals
    s = trimSpaces(s); //trim the spaces
    return res;
}

/**
* remove the Two size boolean operator from the end of the string and remove excess spaces
* @param s string by reference
* @return the operator
*/
string Lexer::extractTwoOperator(string &s) {
    string res = "";
    res += s[s.length()-2];
    res += s[s.length()-1];
    s = s.substr(0,s.length()-2); //remove the equals
    s = trimSpaces(s); //trim the spaces
    return res;
}

/**
* check if the line contain boolean operator of size 2
* @param line string line to check
* @param i the index to check from
* @return true if contains, else false
*/
bool Lexer::isContainBoolTwoOperators(string line, int i) {
    string operatorsTwo[] = {NOT_EQUAL, EQUAL_EQUAL, LESS_EQUAL, GRATER_EQUAL };

    if (i < line.length() - 1) { // make sure there is another char to read
        string s = "";
        s += line[i];
        if (line[i+1] == C_EQUAL) {
            s += line[i+1];
            for (int j = 0; j < 4; j++) {
                if (s == operatorsTwo[j])
                    return true;
            }
        }
        return false;
    } else {
        return false;
    }
}

/**
* check if the line contain boolean operator of size 1
* @param line string line to check
* @param i the index to check from
* @return true if contains, else false
*/
bool Lexer::isContainOneBoolOperator(string line, int i) {
    return (line[i] == C_GRATER || line[i] == C_LESS);
}
/**
* get the rest of the line from given index and remove excess spacess
* @param line string
* @param i the index to get the rest of the line
* @return string- the rest of the line
*/
string Lexer::getRestFromIndex(string line, int i) {
    string s = line.substr(i, line.length() -i );
    s = trimSpaces(s);
    return s;
}

Lexer::Lexer(const string &fileNmae) : fileName(fileNmae) {}
