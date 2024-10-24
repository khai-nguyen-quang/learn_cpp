#pragma once

#include <thread>
#include <atomic>
#include <vector>
#include <functional>
#include <iostream>
#include <future>

#include "threadsafe_queue.hpp"

using namespace std;

/*
    The class ThreadPool creates maximum number of threads according to hardware upon constructor.
    User submits tasks into work_queue_
    Threads in threads_pool_ keep getting tasks stored in work_queue_ then execute them
*/
template<typename FuncType>
class ThreadPool {

public: 
    ThreadPool() :
        complete_(false),
        num_threads_{0}
        
    {
        try {
            num_threads_ = thread::hardware_concurrency();
            create_threads(num_threads_);
        } catch (...) {
            complete_ = true;
            throw;
        }
    }
    ~ThreadPool(){
        complete_ = true;
        for(unsigned long i=0;i<threads_.size();++i)
        {
            std::cout << "[ThreadPool]" << " Wait to stop - thread:" << i  << std::endl;
            if(threads_[i].joinable()) {
                threads_[i].join();
            }            
        }
    }

    auto submit (const function<FuncType>& func) {
        packaged_task<FuncType> task(func);

        auto fut = task.get_future();
        work_queue_.push(move(task));

        return fut;
    }

    uint32_t num_threads() const {
        return num_threads_;
    }

    bool has_task() const {
        return !work_queue_.empty();
    }
private:
    void work_thread(){
        // pop a task being stored in work_queue_ then execute it.
        while(complete_ == false) {
            packaged_task<FuncType> task;
            if (work_queue_.try_pop_movable(task)) {
                task();
            } else {
                this_thread::yield();
            }
        }
    }
    // create maximum possible number of threads.
    // threads in threads_pool_ keep getting tasks from work_queue_ and execute it. 
    void create_threads(uint32_t num_threads) {
        for(uint32_t i=0; i < num_threads; i++) {
            threads_.push_back(
                thread(&ThreadPool::work_thread, this)
            );
        }
    }

    vector<thread> threads_;
    atomic_bool complete_;

    ThreadSafeQueue<packaged_task<FuncType>> work_queue_;
    uint32_t num_threads_;
};