#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

class ValidParentheseSolution {

public:
    bool isValid(string s) {

        for(auto& c : s) {
            // if this is open character, then push it into stack
            if (openType(c) != INVALID) {
                stack_.push(c);
                continue;
                
            }

            // if this is close character, then pop the stack
            // verify if the poped character is open character and has same type
            int closeType = this->closeType(c);
            if (closeType != INVALID) {
                if(!stack_.empty()) {
                    char lastOpenCharacter = stack_.top();
                    int openType = this->openType(lastOpenCharacter);
                    if (openType == closeType) {
                        stack_.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
            
        }
        return (stack_.size() == 0);
    }
private: 
    stack<char> stack_;
    static const int SIZE = 3;
    static const int INVALID = -1;
    const char open[SIZE]  = {'(', '[', '{'};
    const char close[SIZE] = {')', ']', '}'};

    int openType(char c) {
        for (int i=0; i<SIZE; i++){
            if (c == open[i]) return i;
        }
        // cannot find
        return -1;
    }

    int closeType(char c) {
        for (int i=0; i<SIZE; i++){
            if (c == close[i]) return i;
        }
        // cannot find
        return -1;
    }
};