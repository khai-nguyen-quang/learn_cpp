#pragma once

#include <thread>
#include <vector>
#include <iostream>

class ThreadJoiner
{
public:
    explicit ThreadJoiner(std::vector<std::thread>& threads):
        threads_(threads)
    {}
    ~ThreadJoiner() {
        for(unsigned long i=0;i<threads_.size();++i)
        {
            std::cout << "[ThreadJoiner]" << " Wait for stop - thread:" << i  << std::endl;
            if(threads_[i].joinable()) {
                threads_[i].join();
            }            
        }
    }
private:
    std::vector<std::thread>& threads_;
};