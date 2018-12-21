#ifndef THREAD_MANAGER
    #define THREAD_MANAGER

#include "pthread.h"
#include <sys/types.h>
#include <vector>
#include <map>
using namespace std;
class ThreadManager {
public:
    struct thread_detail {
        int id;
        pthread_t thread;
        int parent_id;
    };

    enum knownThread {
        ServerThread = 1, ConnectThread = 2
    };

    ThreadManager();

    int addTheads(pthread_t thread);

    int addThread(pthread_t thread);

    int addThread(pthread_t thread, knownThread known);

    int removeThread(int id);

    bool isThreadExist(int id);

    thread_detail getThreadDetail(int id);

    thread_detail getThreadDetail(pthread_t thread);

    int getThreadId(pthread_t thread);

    thread_detail getThreadParent(int id);

    int getThreadQuantity();

    bool isThereSubThread(int id);

    void runThread(int id);

    void runThread(pthread_t pthread);

    void waitForThread(int id);
private:
    map<int, thread_detail> threads;

};


#endif
