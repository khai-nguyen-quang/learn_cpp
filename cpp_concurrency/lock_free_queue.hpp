#pragma once

#include <atomic>
#include <memory>

using namespace std;

template<typename T>
class LockFreeQueue {

public: 
    /*
       (head) node --> node --> ... --> node --> node(share_ptr<T>(), null) (tail)
    */

    LockFreeQueue():
        head{nullptr}, 
        tail{nullptr}
    {}

    LockFreeQueue(const LockFreeQueue& q) = delete;
    LockFreeQueue& operator=(const LockFreeQueue& q) = delete;

    ~LockFreeQueue() {
        while (node* oldhead = head.load()){
            head.store(oldhead->next);
            delete oldhead;
        }
    }

    shared_ptr<T> pop() {
        node* old_head = pop_head();
        if (!old_head) return shared_ptr<T>();

        shared_ptr<T> res (old_head->data);

        delete old_head;
        return res;
    }

    void push (T new_value){
        // push new node at tail, then update tail 
        std::shared_ptr<T> new_data(std::make_shared<T>(new_value));
        node* p=new node;

        node* const old_tail=tail.load();
        old_tail->data.swap(new_data);
        old_tail->next=p;

        tail.store(p);
    }
private:
    struct node {
        shared_ptr<T> data;
        node* next;
        node() : 
            next{nullptr}
        {}

    };
    atomic<node*> head;
    atomic<node*> tail;

    node* pop_head(){
        node* old_head = head.load();

        if (old_head == tail.load()) {
            return nullptr;
        }

        head.store(old_head->next);
        return old_head;
    }
};