#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

#include <string>
#include <map>
class Var;
using namespace std;
/**
 * the SymbolTable hold a map between the their name and tha Var itself, also it mange a map between paths and the
 * var's name. we can add variables to the maps
 */
class SymbolTable {
private:
    map < string, Var* > variables; // map between the string name of the var to the actual Var*
    map < string, string> paths; // map between the path of the vars to their name
public:
    /**
     * add variable to the variables map
     * @param var: name of the var
     * @param value: the value to set to the var
     * @param isBind indicate if the var is bind to the server
     */
    void addVariable(string var, double value, bool isBind);

    /**
     * add variable to the variables map, with isBind is false
     * @param var: name of the
     * @param value: the value to set to the var
     */
    void addVariable(string var, double value);

    /**
     * remove variable from the variables map
     * @param var: name of the var
     * @return the number of element erase
     */
    unsigned long removeVariable(string var);

    /**
     * swt the value of var inside the variables map
     * @param var: name of the var
     * @param value: the value to set to the var
     */
    void setValue(string var, double value);

    /**
     * update existing var inside the variables map
     * @param var Var by reference
     */
    void updateVariable(Var& var);

    /**
     * get variable value
     * @param var: name of the var
     * @return the value of the var
     */
    double getVariable(string var) ;

    /**
     * check whether the variable's value equals to the given value
     * @param var: var's name
     * @param value: var's value
     * @return true if equals, else false
     */
    bool isVariableEquels(string var, double value);

    /**
     * check if the variable exist inside the variables map
     * @param var: var name
     * @return true if exist, else false
     */
    bool isVariableExist(string var) ;

    /**
     * get the var's pointer by name
     * @param var: string name
     * @return Var*
     */
    Var * getVar(string var);

    /**
     * set value and isBind to var
     * @param varName: the var name
     * @param value: the value to be set
     * @param isBind: true if the var isBind, else false
     */
    void setValueAndBind(string varName, double value, bool isBind);

    /**
     * set IsBind
     * @param varName: name of the var
     * @param isBind: boolean
     */
    void setIsBind(string varName, bool isBind);

    /**
     * add path to paths map
     * @param path: string path
     * @param varName: var's name
     */
    void addPath(string path, string varName);
    /**
     * check if path is exist in paths map
     * @param path: the path to check
     * @return true if path exist, else false
     */
    bool isPathExist(string path);
    /**
     * get var's name by path
     * @param path: string path to be checked
     * @return the name of the var
     */
    string getVarNameByPath(string path);
    /**
     * get var by path
     * @param path: string path
     * @return Var*
     */
    Var* getVarByPath(string path);

    string getPathByVar(string varName);//todo: to ran, you can write the code inside or delete it
    /**
     * destructor, free memory
     */
    virtual ~SymbolTable();
};


#endif