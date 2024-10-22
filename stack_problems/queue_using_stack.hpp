/*
232. Implement Queue using Stacks
https://leetcode.com/problems/implement-queue-using-stacks/description/?envType=problem-list-v2&envId=stack&difficulty=EASY
 */

/*
// Queue
    push --> 3 --> 2 --> 1 --> front

   stack 
    1 --> 2 --> 3 --> 4 --> push/pop

    // move everything in main-stack to tmp-stack
    main-stack: 
    tmp-stack : 1
    
    // add new element to main stack
    main-stack: 2
    tmp-stack : 1

    // move back everything from tmp stack to main stack
    main-stack: 2 --> 1
    tmp-stack : 

    main-stack: 3
    tmp-stack : 1 --> 2

*/

#include <stack>

using namespace std;

class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        // move everything in main-stack to tmp-stack
        while(!mainStack_.empty()) {
            tmpStack_.push(mainStack_.top());
            mainStack_.pop();
        }

        // add new element to main stack
        mainStack_.push(x);

        // move back everything from tmp stack to main stack
        while(!tmpStack_.empty()) {
            mainStack_.push(tmpStack_.top());
            tmpStack_.pop();
        }
    }
    
    int pop() {
        if (!mainStack_.empty()) {
            int result = mainStack_.top();
            mainStack_.pop();

            return result;
        } else return -1;
    }
    
    int peek() {
       if (!mainStack_.empty()) return mainStack_.top(); 
       else return -1;
    }
    
    bool empty() {
        return mainStack_.empty();
    }
private: 
    stack<int> mainStack_;
    stack<int> tmpStack_; 
};
