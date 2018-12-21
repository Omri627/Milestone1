
#ifndef PROJECT_SYMBOLUPDATER_H
#define PROJECT_SYMBOLUPDATER_H
#define SIZE 512

#include <vector>
#import "SymbolTable.h"
#include "Var.h"

using namespace std;

class SymbolUpdater {

private:
    SymbolTable* symbolTable;
    vector<string> pathsVec;

    void loadPath();

    void updateVar(double value, string path);
public:

    SymbolUpdater(SymbolTable *symbolTable);

    void update(char buffer[SIZE]);

};


#endif //PROJECT_SYMBOLUPDATER_H
