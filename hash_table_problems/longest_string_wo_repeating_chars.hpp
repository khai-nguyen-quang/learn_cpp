/*
3. Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/?envType=problem-list-v2&envId=hash-table
*/

#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

class LongestStringWoRepeatChars {
public:
    int lengthOfLongestSubstring(string s) {
        list<char> apperance{}; // <character, order>
        uint32_t max_len{0}, cur_len{0};

        list<char>::iterator it;
        for(char& c : s) {
            // first character in string
            if (apperance.empty()) {
                apperance.push_back(c);
                cur_len = 1;
                it = apperance.begin();
            } 
            // from 2nd character onwards
            else {

                // the character is not present yet
                auto pre_it  = find (apperance.begin(), apperance.end(), c);

                if (pre_it == apperance.end()) {
                    apperance.push_back(c);
                    cur_len++;
                } 
                // the character is existing, erase all characters before c
                else {
                    std::advance(pre_it, 1);
                    apperance.erase(apperance.begin(), pre_it);
                    apperance.push_back(c);
                    cur_len = apperance.size();
                }
            }

            // cout << cur_len << endl;
            max_len = max(max_len, cur_len);
        }
        return max_len;
    }
};