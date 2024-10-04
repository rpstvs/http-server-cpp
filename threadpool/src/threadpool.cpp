
#include "threadpool.h"

ThreadPool::ThreadPool(int num_threads)
{
    for (int i = 0; i < num_threads; i++)
    {
        workers.emplace_back([this]
        {
            for(;;)
            {
                
                std::unique_lock<std::mutex> lock(queue_mutex_);
                cv.wait(lock, [this]
                {
                    return stop || !tasks.empty();
                });
                if (stop, tasks.empty())
                {
                    return;
                }
                auto task = std::move(tasks.front());
                tasks.pop();
                lock.unlock();
                task();
            }
        });
    }
    
}

ThreadPool::~ThreadPool()
{
    std::unique_lock<std::mutex> lock(queue_mutex_);
    stop=true;

    cv.notify_all();

    for(auto &thread:workers)
    {
        thread.join();
    }
}

void ThreadPool::enqueue(std::function<void()> task)
{
    {
        std::unique_lock<std::mutex> lock(queue_mutex_);
        tasks.emplace(move(task));
    }
    cv.notify_one();
}

std::string ThreadPool::get_thread_id()
{
    auto id = std::this_thread::get_id();
    std::stringstream ss;
    ss << id;
    std::string mystr = ss.str();
    return mystr;
}