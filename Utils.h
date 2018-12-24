#ifndef PROJECT_UTILS_H
#define PROJECT_UTILS_H

#include <string>
#include <pthread.h>

using namespace std;

static pthread_mutex_t g__mutex;

class Utils {
public:
    static string reverseStr(string str);

};


#endif //PROJECT_UTILS_H
