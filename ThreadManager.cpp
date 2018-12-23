#include <thread>
#include <unistd.h>
#include "ThreadManager.h"
ThreadManager::ThreadManager() {
    //@todo add main thread
    this->addThread(pthread_self(),MAIN_THREAD);
}

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
int ThreadManager::addThread(pthread_t thread, knownThread known) {
    //@ todo changes parent id
    thread_detail detail;
    detail.thread = thread;
    detail.id = known;
    if (detail.id != 0)
        detail.parent_id =  this->getThreadId(pthread_self());
    this->threads[detail.id] = detail;
    return detail.id;
}
ThreadManager::thread_detail ThreadManager::getThreadDetail(int id) {
    if (!this->isThreadExist(id))
        throw "thread is not exist";
    return this->threads[id];
}
bool ThreadManager::isThreadExist(int id) {
    map< int, thread_detail >::iterator iterator;
    iterator = this->threads.find(id);
    if (iterator == this->threads.end())
        return false;
    return true;
}
int ThreadManager::removeThread(int id) {
    if (!this->isThreadExist(id))
        return 0;
    this->threads.erase(id);
    return 1;
}
int ThreadManager::removeThread(pthread_t pthread) {
    int id = this->getThreadId(pthread);
    this->threads.erase(id);
    return 1;
}
int ThreadManager::getThreadQuantity() {
    this->threads.size();
}
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
void ThreadManager::runThread(int id) {
    pthread_detach(this->getThreadDetail(id).thread);
}
void ThreadManager::runThread(pthread_t thread) {
    pthread_detach(thread);
}
void ThreadManager::waitForThread(int id) {
    pthread_join(this->threads[id].thread, nullptr);
}
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
ThreadManager::thread_detail ThreadManager::getThreadParent(int id) {
    thread_detail thread = this->getThreadDetail(id);
    return this->threads[thread.parent_id];
}
int ThreadManager::getThreadId(pthread_t thread) {
    thread_detail thread_detail = this->getThreadDetail(thread);
    return thread_detail.id;
}
void ThreadManager::closeMainThread() {
    while (isThereSubThread(MAIN_THREAD))
        sleep(1000);
    this->threads.clear();
    exit(0);
}