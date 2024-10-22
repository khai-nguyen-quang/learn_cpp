/*
https://leetcode.com/problems/generate-parentheses/description/?envType=problem-list-v2&envId=dynamic-programming&difficulty=MEDIUM
*/

#include <bits/stdc++.h>
#include <vector>

using namespace std;

class GenerateParenthese {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> result;
        generateParenthesisHelper(0, 0, n, "", result);
        return result;
    }

    void generateParenthesisHelper(uint open, uint close, uint n, std::string current, std::vector<std::string>& result) {
        if (current.size() == 2 * n) {
            result.push_back(current);
            return;
        }

        if (open < n) {
            generateParenthesisHelper(open + 1, close, n, current + "(", result);
        }
        if (close < open) {
            generateParenthesisHelper(open, close + 1, n, current + ")", result);
        }
    }
};