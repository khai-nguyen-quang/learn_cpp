#include <bits/stdc++.h>
#include <thread>
#include <string>
#include <array>
#include "cpp_concurrency/threadsafe_queue.hpp"

template <typename T>
void write_operation(ThreadSafeQueue<T>& q, atomic_bool& complete, vector<T> data) {
    for (T& s : data) {
        this_thread::sleep_for(chrono::milliseconds(500));
        q.push(s);
    }
    complete.store(true);
}

template <typename T>
void read_operation(ThreadSafeQueue<T>&q, atomic_bool& complete) {

    while(complete.load() == false) {
        cout << *(q.wait_and_pop()) << endl; 
    }  
    
}

void main_concurrency() {
    ThreadSafeQueue<int> q{};
    vector<int> data{1,2,3,4,5,6,7,8,9,10};
    atomic_bool complete = ATOMIC_FLAG_INIT;

    std::thread write_thread(write_operation<int>, ref(q), ref(complete), ref(data));
    std::thread read_thread(read_operation<int>, ref(q), ref(complete));

    write_thread.join();
    read_thread.join();

    cout << "Completed" << endl;
}