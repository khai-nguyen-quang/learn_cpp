#pragma once

#include <queue>
#include <memory>
#include <mutex>
#include <condition_variable>

using namespace std;

template <typename T>
class ThreadSafeQueue {

public : 
    explicit ThreadSafeQueue(){}
    explicit ThreadSafeQueue( const ThreadSafeQueue& q) {
        lock_guard<mutex> guard(q.mx_queue_);
        data_queue_ = q.data_queue_;
    }
    ThreadSafeQueue& operator=(const ThreadSafeQueue& q) = delete;

    ~ThreadSafeQueue() {
        // cout << "[ThreadSafeQueue]" << " Destroying object " << endl;
    }
    void push(const T& new_value) {
        lock_guard<mutex> lk(mx_queue_);
        data_queue_.push(new_value);

        cv_queue_.notify_all();
    }

    void push(T&& new_value) {
        lock_guard<mutex> lk(mx_queue_);
        data_queue_.push(std::move(new_value));

        cv_queue_.notify_all();
    }

    // wait until data queue is not empty
    void wait_and_pop(T& value) {
        unique_lock<mutex> lk(mx_queue_);
        cv_queue_.wait(lk, [this]{
            return !data_queue_.empty();
        });

        value = data_queue_.front();
        data_queue_.pop();
    }
    shared_ptr<T> wait_and_pop() {
        unique_lock<mutex> lk(mx_queue_);
        cv_queue_.wait(lk, [this]{
            return !data_queue_.empty();
        });

        shared_ptr<T> res = make_shared<T>(data_queue_.front());
        data_queue_.pop();

        return res;
    }
    bool try_pop(T& value)
    {
        lock_guard<mutex> lk(mx_queue_);

        if (data_queue_.empty()) return false;

        value = data_queue_.front();
        data_queue_.pop();
        return true;
    }

    bool try_pop_movable(T& value)
    {
        lock_guard<mutex> lk(mx_queue_);

        if (data_queue_.empty()) return false;

        value = std::move(data_queue_.front());
        data_queue_.pop();
        return true;
    }

    std::shared_ptr<T> try_pop() {
        lock_guard<mutex> lk(mx_queue_);
        if (data_queue_.empty()) return shared_ptr<T>{};

        shared_ptr<T> res = make_shared<T>(data_queue_.front());
        data_queue_.pop();
        return res;
    }

    bool empty() const {
        lock_guard<mutex> lk(mx_queue_);
        return data_queue_.empty();
    }

private : 
    mutable  mutex mx_queue_;
    condition_variable cv_queue_;
    queue<T> data_queue_;
};