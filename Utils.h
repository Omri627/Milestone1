#ifndef PROJECT_UTILS_H
#define PROJECT_UTILS_H

#include <string>
extern pthread_mutex_t global_mutex;

using namespace std;

class Utils {
public:
    static string reverseStr(string str);

};


#endif //PROJECT_UTILS_H
