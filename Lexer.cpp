#include <fstream>
#include "Lexer.h"
vector<string> Lexer::getSplitFromFile() {

    ifstream infile;
    infile.open("script.txt", ios::in);
    if (!infile.is_open()) {
        throw "file did not opened";
    }
    char space = ' ';
    string line;
    while (getline(infile, line)) {
        if (!line.empty()) {
            for (int i = 0; i < line.length(); i++) {
                if (line[i] != space) {
                    //endIndex is the end index of the word
                    int endIndex = line.find_first_of(" ", i);
                    string word;//= line.substr(i, endIndex -1);

                    if (endIndex != -1) {
                        //if there space after the word
                        if (line[i] == '=') {
                            if (line.find("bind", i) == -1){
                                //there is no bind keyword
                                codeLine.push_back("=");
                                i++;
                                if (i < line.length()) {
                                    //read the expression until the end of the line
                                    word = line.substr(i);
                                    word = trimSpaces(word);
                                    i = line.length();
                                }
                            } else {
                                //word is = but there is no bind
                                word = "=";
                                i++;
                            }
                        } else {
                            //read regular word that have space afterword
                            int length = endIndex - i; // the length of the string
                            word = line.substr(i, length);
                            i += length;

                        }
                    } else {
                        //there is no space after the word
                        word = line.substr(i);
                        i = line.length();
                    }
                    codeLine.push_back(word);
                }
            }
        }
    }
    return codeLine;
}

string Lexer::trimSpaces(string s) {
    int start = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' '){
            start++;
        } else {
            break;
        }
    }
    int count = 0;
    for (int i = s.length() - 1; i > 0; i--) {
        if (s[i] == ' '){
            count++;
        } else {
            break;
        }
    }
    s = s.substr(start, s.length() - start - count);
    return s;
}