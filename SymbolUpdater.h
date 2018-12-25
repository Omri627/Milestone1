
#ifndef PROJECT_SYMBOLUPDATER_H
#define PROJECT_SYMBOLUPDATER_H
#define SIZE 512

#include <vector>
#include "SymbolTable.h"
#include "Var.h"

using namespace std;
/**
 * the symbolUpdater updates the binds var from the parameters that we got from the DataServer
 */
class SymbolUpdater {

private:
    /* symbol table object */
    SymbolTable* symbolTable;
    /* holding path of variables in simulator server. */
    vector<string> pathsVec;

    /**
    * load the path into the paths vector
    */
    void loadPath();

    /**
    * update the value of the var
    * @param value: the value to update
    * @param path: the path of the var
    */
    void updateVar(double value, string path);
public:
    /**
     * constructor
     * @param symbolTable symbolTable that holds the map of vars
     */
    SymbolUpdater(SymbolTable *symbolTable);

    /**
    * update each bind var from the information that got from the server
    * @param buffer
    */
    void update(char buffer[SIZE]);

    virtual ~SymbolUpdater();
};


#endif