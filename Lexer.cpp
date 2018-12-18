#include <fstream>
#include <iostream>
#include "Lexer.h"
#define EQUAL "="
#define C_EQUAL '='
#define C_PLUS '+'
#define C_MINUS '-'
#define C_MUL '*'
#define C_DIV '/'
#define C_POW '^'
#define C_SPACE ' '
#define C_COMMA ','
vector<string> Lexer::getSplitFromFile(string filename) {

    ifstream infile;
    infile.open(filename, ios::in);
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
                }
                if (word.find(EQUAL) != -1) {
                    extractEqual(word);
                    word = trimSpaces(word);
                    codeLine.push_back(word);
                    codeLine.push_back(EQUAL);
                    i++;
                } else {
                    codeLine.push_back(word);
                }
            }
        }
    }
    infile.close();
    return codeLine;
}

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

string Lexer::getOneExpression(string line, int &i) {
    int temp = i;
    bool isSign = false;
    bool isSpaceBefore = false;
    bool isBreak = false;
    int endIndex = i;

    for (i; i < line.length(); i++) {
        char cc = line[i];
        //loop through line
        if (line[i] == C_EQUAL) {
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

void Lexer::extractEqual(string &s) {
    s = s.substr(0,s.length()-1); //remove the equals
    s = trimSpaces(s); //trim the spaces
}