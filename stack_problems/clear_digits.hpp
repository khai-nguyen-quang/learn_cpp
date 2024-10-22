/*
3174. Clear Digits
https://leetcode.com/problems/clear-digits/description/?envType=problem-list-v2&envId=stack&difficulty=EASY
*/

#include <string>
#include <stack>
using namespace std;

class ClearDigitsSolution {
public:
    string clearDigits(string s) {
        string result = "";
        stack<char> output ; 

        for (auto& c : s) {
            if (isdigit(c)) {
                if (!output.empty()){
                    output.pop();
                }
            } else {
                output.push(c);
            }
        }
        while(!output.empty()){
            result = output.top() + result;
            output.pop();
        }

        return result;  
    }
};