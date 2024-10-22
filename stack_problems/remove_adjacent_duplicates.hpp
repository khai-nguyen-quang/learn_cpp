/* 
1047. Remove All Adjacent Duplicates In String
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/?envType=problem-list-v2&envId=stack&difficulty=EASY
*/

#include <bits/stdc++.h>
#include <string>
#include <stack>

using namespace std;
class RemoveAdjacentDuplicatesSolution {
public:
    string removeDuplicates(string s) {
        stack<char> output;

        for (auto& c : s) {
            if (!output.empty()) {
                if (c == output.top()) output.pop();
                else output.push(c);
            } else {
                output.push(c);
            }
        }
        string result = "";
        while(!output.empty()) {
            result = output.top() + result;
            output.pop();
        }
        return result;
    }
};