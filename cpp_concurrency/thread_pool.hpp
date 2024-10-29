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

/*
    TaskType is a type that wraps a function.
    TaskType is copy-able type which can be added to ThreadSafeQueue
*/

template <typename FuncType> 
struct TaskType {
    shared_ptr<packaged_task<FuncType>> task;

    TaskType(function<FuncType>& f)
    {
        task = make_shared<packaged_task<FuncType>>(packaged_task<FuncType>(f));
    }

    TaskType() = default;

    // unsupport move constructor/operator
    TaskType(TaskType&& other) = delete;
    TaskType& operator=(TaskType&& other) = delete;

    // support copy constructor/operator
    TaskType(const TaskType& other) : 
        task(other.task) 
    {}

    TaskType(TaskType& other) : 
        task(other.task)
    {}

    TaskType& operator=(const TaskType& other)
    {
        task = other.task;
        return *this;
    }

    void operator()(){
        if (task) {
            (*task)();
        }
    }

    typedef invoke_result_t<FuncType> FuncRetType;
    future<FuncRetType> get_future() const {
        return (*task).get_future();
    }
};

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

    typedef  std::invoke_result_t<FuncType> FuncRetType;
    future<FuncRetType> submit (function<FuncType> task_) {
        
        TaskType<FuncType> task(task_);
        future<FuncRetType> fut = task.get_future();
        work_queue_.push(task);

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
            TaskType<FuncType> task;
            if (work_queue_.try_pop(task)) {
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

    ThreadSafeQueue<TaskType<FuncType>> work_queue_;
    uint32_t num_threads_;
};