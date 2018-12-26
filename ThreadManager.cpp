#include <thread>
#include <unistd.h>
#include "ThreadManager.h"

/**
 * Creates an empty thread manager
 */
ThreadManager::ThreadManager() {
    /* adding main thread */
    this->addThread(pthread_self(),MAIN_THREAD);
}
/**
 * addThread method inserts a single thread into storage
 * @param thread given thread object
 * @return if the thread inserted successfully the method returns value 1
 * at any other case returns 0
 */
int ThreadManager::addThread(pthread_t thread) {
    /* thread ids 0-3 reserved */
    static int threadCounter = 4;
    thread_detail detail;
    detail.thread = thread;
    detail.id = threadCounter++;
    detail.parent_id =  0;
    this->threads[detail.id] = detail;
    return detail.id;
}
/**
 * addThread method inserts a known thread into storage.
 * @param thread thread object
 * @param known known thread type
 * @return if the thread inserted successfully the method returns value 1
 * at any other case returns 0
 **/
int ThreadManager::addThread(pthread_t thread, knownThread known) {
    thread_detail detail;
    detail.thread = thread;
    detail.id = known;
    if (detail.id != 0)
        detail.parent_id =  this->getThreadId(pthread_self());
    this->threads[detail.id] = detail;
    return detail.id;
}
/**
 * getThreadDetail method gets id of thread
 * and returns details entry of this thread
 * @param id id of thread
 * @return returns stored details of the given thread-id
 */
ThreadManager::thread_detail ThreadManager::getThreadDetail(int id) {
    if (!this->isThreadExist(id))
        throw "thread is not exist";
    return this->threads[id];
}
/**
 * isThreadExist method gets id of thread and checks
 * whether this id is exist in storage.
 * @param id id of thread
 * @return returns true if there is a thread with the given id in storage
 * at any other case returns 0
*/
bool ThreadManager::isThreadExist(int id) {
    map< int, thread_detail >::iterator iterator;
    iterator = this->threads.find(id);
    if (iterator == this->threads.end())
        return false;
    return true;
}
/**
 * removeThread method gets thread id and delete the thread from storage
 * @param id id of specific thread
 * @return if the operation completed successfully the method returns value 1
 * at any other case returns 0
 */
int ThreadManager::removeThread(int id) {
    if (!this->isThreadExist(id))
        return 0;
    this->threads.erase(id);
    return 1;
}
/**
 * removeThread method gets thread object and delete the thread from storage
 * @param id id of specific thread
 * @return if the operation completed successfully the method returns value 1
 * at any other case returns 0
 */
int ThreadManager::removeThread(pthread_t pthread) {
    int id = this->getThreadId(pthread);
    this->threads.erase(id);
    return 1;
}
/**
 * getThreadQuantity method returns the thread quantity in storage
 * @return returns the thread quantity in storage
 */
int ThreadManager::getThreadQuantity() {
    this->threads.size();
}
/**
 * isThereSubThread method gets id of thread
 * and checks if there are threads subordinates to him.
 * @param id id of thread
 * @return returns true if there are subthread of the given thread.
 */
bool ThreadManager::isThereSubThread(int id) {
    map <int, thread_detail >::iterator iterator;
    iterator = this->threads.begin();
    while (iterator != this->threads.end()) {
        if (iterator->second.parent_id == id)
            return true;
        iterator++;
    }
    return false;
}
/**
 * waitForThread join the running thread to thread with the given id.
 * @param id id of thread
 */
void ThreadManager::waitForThread(int id) {
    pthread_join(this->threads[id].thread, nullptr);
}
/**
 * getThreadDetail method pthread object
 * and returns details entry of this thread
 * @param id id of thread
 * @return returns stored details of the given thread
 */
ThreadManager::thread_detail ThreadManager::getThreadDetail(pthread_t thread) {
    map <int, thread_detail >::iterator iterator;
    iterator = this->threads.begin();
    while (iterator != this->threads.end()) {
        if (iterator->second.thread == thread)
            return iterator->second;
        iterator++;
    }
    throw "thread not exist";
}
/**
 * getThreadParent method gets id of thread
 * and returns parent thread id of given thread.
 * i.e the thread which creates it or the thread which the given thread subordinates to
 * @param id id of thread
 * @return parent thread id of given thread
 */
ThreadManager::thread_detail ThreadManager::getThreadParent(int id) {
    thread_detail thread = this->getThreadDetail(id);
    return this->threads[thread.parent_id];
}
/**
 * getThreadId methods gets thread objects
 * and returns thread's id
 * @param thread thread object
 * @return returns thread id of given pthread
 */
int ThreadManager::getThreadId(pthread_t thread) {
    thread_detail thread_detail = this->getThreadDetail(thread);
    return thread_detail.id;
}
/**
 * closeMainThread closes the main thread.
 * when his sub-threads finished their tasks.
 */
void ThreadManager::closeMainThread() {
    while (isThereSubThread(MAIN_THREAD))
        sleep(1000);
    this->threads.clear();
    exit(0);
}
/**
 * destructor, free memory.
 */
ThreadManager::~ThreadManager() {
    this->threads.clear();
}

