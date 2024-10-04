
#include <pthread.h>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>
#include <sstream>


#define THREAD_POOL_SIZE 10




class ThreadPool
{   

    
    public:
    ThreadPool(int thread_size);
    ~ThreadPool();

    void enqueue(std::function<void()> task);

    std::string get_thread_id();

    private:
    std::vector<std::thread> workers;

    std::queue<std::function<void()>> tasks;

    std::mutex queue_mutex_;

    std::condition_variable cv;

    bool stop = false;
};