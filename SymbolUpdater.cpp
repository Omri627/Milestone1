#include <iostream>
#include "SymbolUpdater.h"
#define COMMA ","


SymbolUpdater::SymbolUpdater(SymbolTable *symbolTable) : symbolTable(symbolTable) {
    loadPath();
}

void SymbolUpdater::loadPath() {

    pathsVec.emplace_back("/instrumentation/airspeed-indicator/indicated-speed-kt");
    pathsVec.emplace_back("/instrumentation/altimeter/indicated-altitude-ft");
    pathsVec.emplace_back("/instrumentation/altimeter/pressure-alt-ft");
    pathsVec.emplace_back("/instrumentation/attitude-indicator/indicated-pitch-deg");
    pathsVec.emplace_back("/instrumentation/attitude-indicator/indicated-roll-deg");
    pathsVec.emplace_back("/instrumentation/attitude-indicator/internal-pitch-deg");
    pathsVec.emplace_back("/instrumentation/attitude-indicator/internal-roll-deg");
    pathsVec.emplace_back("/instrumentation/encoder/indicated-altitude-ft");
    pathsVec.emplace_back("/instrumentation/encoder/pressure-alt-ft");
    pathsVec.emplace_back("/instrumentation/gps/indicated-altitude-ft");
    pathsVec.emplace_back("/instrumentation/gps/indicated-ground-speed-kt");
    pathsVec.emplace_back("/instrumentation/gps/indicated-vertical-speed");
    pathsVec.emplace_back("/instrumentation/heading-indicator/indicated-heading-deg");
    pathsVec.emplace_back("/instrumentation/magnetic-compass/indicated-heading-deg");
    pathsVec.emplace_back("/instrumentation/slip-skid-ball/indicated-slip-skid");
    pathsVec.emplace_back("/instrumentation/turn-indicator/indicated-turn-rate");
    pathsVec.emplace_back("/instrumentation/vertical-speed-indicator/indicated-speed-fpm");
    pathsVec.emplace_back("/controls/flight/aileron");
    pathsVec.emplace_back("/controls/flight/elevator");
    pathsVec.emplace_back("/controls/flight/rudder");
    pathsVec.emplace_back("/controls/flight/flaps");
    pathsVec.emplace_back("/controls/engines/engine/throttle");
    pathsVec.emplace_back("/engines/engine/rpm");

}

void SymbolUpdater::update(char *buffer) {
    string buff = string(buffer);
    vector<string>::iterator it; //create iterator
    it = pathsVec.begin(); // the iterator push to the beginning of the vector

    int start = 0; // start index for param
    int end = 0; // end index for the param
    double value;

    for (start = 0; start < buff.length(); start++) {
        string param;
        end = buff.find(COMMA ,start);
        if (end == string::npos) {
            //last param, read to the end
            param = buff.substr(start);
            value = stod(param);
            updateVar(value, *it);
            break;
        } else {
            param = buff.substr(start, end - start);
        }
        start = end; // point to the next comma

        value = stod(param);
        updateVar(value, *it);
        if (it != pathsVec.end()) {
            it++;
        }
    }
}

void SymbolUpdater::updateVar(double value, string path) {
    //symbolTable->setValue(path, value);
    Var* var = symbolTable->getVarByPath(path);
    if (var != nullptr) {
        var->setValue(value);
    }
}
void SymbolUpdater::printBinds() { //todo:: delete later, for debugging only
    for (string s : pathsVec) {
        Var* var = symbolTable->getVarByPath(s);
        if (var!= nullptr) {
            cout << var->getVariableName() << ": " << var->getValue() <<endl;
        }
    }
}

