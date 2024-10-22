/*
225. Implement Stack using Queues
https://leetcode.com/problems/implement-stack-using-queues/description/?envType=problem-list-v2&envId=stack&difficulty=EASY
*/

#include <string>
#include <queue>
using namespace std;

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

class MyStack {
public:
    // back --> 1 --> 2 --> top
    MyStack() {
        
    }
    
    void push(int x) {
        // push new element into tmp queue
        // pop all elements in main queue to main queue
        // swap main & tmp queues
        tmpQueue_.push(x);
        while(!mainQueue_.empty()) {
            int e = mainQueue_.front();
            tmpQueue_.push(e);
            mainQueue_.pop();
        }

        swap(tmpQueue_, mainQueue_);

    }
    
    int pop() {
        if (mainQueue_.empty()) return -1;
        
        int result = mainQueue_.front();
        mainQueue_.pop();
        return result;
    }
    
    int top() {
        if (mainQueue_.empty()) return -1;
        else return mainQueue_.front();
    }
    
    bool empty() {
        return mainQueue_.empty();
    }
private:
    //push to back
    //pop from front
    // size 
    // empty
    // push back --> 1 --> 2 --> pop front
    queue<int> mainQueue_;
    queue<int> tmpQueue_;

};