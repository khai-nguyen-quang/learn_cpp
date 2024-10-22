#include <bits/stdc++.h>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class RemoveOutermostParentheseSolution {
public:
    string removeOuterParentheses(string s) {
        vector<string> primitive_;
        string tmpString = "";
        int sum = 0;
        for(char& c: s) {
            if (c == '(') sum++;
            else if ( c == ')') sum--;
            else {
                //invalid character here. Unexpected;
                return "";
            }

            // primitive string is found
            tmpString += c;
            if (sum == 0) {
                primitive_.push_back(tmpString);
                tmpString = "";
                sum = 0;
            } else if (sum < 0) {
                //invalid here. Unexpected;
                return "";
            }
        }

        // remove the outermost parenthese of every primitive strings
        for (auto& s : primitive_) {
            s = s.substr(1, s.size() -2);
        }

        string result = "";
        for (auto& s : primitive_) {
            result = result + s;
        }

        return result;
    }
};