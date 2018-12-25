#ifndef THREAD_MANAGER
    #define THREAD_MANAGER

#include "pthread.h"
#include <sys/types.h>
#include <vector>
#include <map>
using namespace std;


static pthread_mutex_t g__mutex;

class ThreadManager {
public:
    /**
     * thread_detail struct holds information about single thread
     */
    struct thread_detail {
        int id;
        pthread_t thread;
        int parent_id;
    };
    /**
     * known thread id
     */
    enum knownThread {
        MAIN_THREAD=0, SERVER_THREAD = 1, SERVER_LISTEN_THREAD = 2, CONNECT_THREAD = 3
    };
    /**
     * Creates an empty thread manager
     */
    ThreadManager();
    /**
     * addThread method inserts a single thread into storage
     * @param thread given thread object
     * @return if the thread inserted successfully the method returns value 1
     * at any other case returns 0
     */
    int addThread(pthread_t thread);
    /**
     * addThread method inserts a known thread into storage.
     * @param thread thread object
     * @param known known thread type
     * @return if the thread inserted successfully the method returns value 1
     * at any other case returns 0
     **/
    int addThread(pthread_t thread, knownThread known);
    /**
     * removeThread method gets thread id and delete the thread from storage
     * @param id id of specific thread
     * @return if the operation completed successfully the method returns value 1
     * at any other case returns 0
     */
    int removeThread(int id);
    /**
     * removeThread method gets thread object and delete the thread from storage
     * @param id id of specific thread
     * @return if the operation completed successfully the method returns value 1
     * at any other case returns 0
     */
    int removeThread(pthread_t pthread);
    /**
     * isThreadExist method gets id of thread and checks
     * whether this id is exist in storage.
     * @param id id of thread
     * @return returns true if there is a thread with the given id in storage
     * at any other case returns 0
    */
    bool isThreadExist(int id);
    /**
     * getThreadDetail method gets id of thread
     * and returns details entry of this thread
     * @param id id of thread
     * @return returns stored details of the given thread-id
     */
    thread_detail getThreadDetail(int id);
    /**
     * getThreadDetail method pthread object
     * and returns details entry of this thread
     * @param id id of thread
     * @return returns stored details of the given thread
     */
    thread_detail getThreadDetail(pthread_t thread);
    /**
     * getThreadId methods gets thread objects
     * and returns thread's id
     * @param thread thread object
     * @return returns thread id of given pthread
     */
    int getThreadId(pthread_t thread);
    /**
     * getThreadParent method gets id of thread
     * and returns parent thread id of given thread.
     * i.e the thread which creates it or the thread which the given thread subordinates to
     * @param id id of thread
     * @return parent thread id of given thread
     */
    thread_detail getThreadParent(int id);
    /**
     * getThreadQuantity method returns the thread quantity in storage
     * @return returns the thread quantity in storage
     */
    int getThreadQuantity();
    /**
     * isThereSubThread method gets id of thread
     * and checks if there are threads subordinates to him.
     * @param id id of thread
     * @return returns true if there are subthread of the given thread.
     */
    bool isThereSubThread(int id);
    /**
     * waitForThread join the running thread to thread with the given id.
     * @param id id of thread
     */
    void waitForThread(int id);
    /**
     * closeMainThread closes the main thread.
     * when his sub-threads finished their tasks.
     */
    void closeMainThread();

    virtual ~ThreadManager();

private:
    /* holds information about threads in program. */
    map<int, thread_detail> threads;

};


#endif
