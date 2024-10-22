#include <iostream>
#include "hash_table_problems/longest_string_wo_repeating_chars.hpp"

using namespace std;


void test_longest_string_wo_repeating_chars(){
    LongestStringWoRepeatChars sol{};

    string inputs[] = {"", "a", "bbbbb", "abba", "ynyo", "abcabcbb", "abcb", "pwwkew", "abcabcbb", "abcadef", "abcbdef", "abccdef", "dvdf"};
    // string inputs[]  = {"ynyo"};
    for (auto& input : inputs){
        cout << "Input: " << input << ": " << sol.lengthOfLongestSubstring(input) << endl;
    }
}

void main_hashtable() {
    test_longest_string_wo_repeating_chars();
}