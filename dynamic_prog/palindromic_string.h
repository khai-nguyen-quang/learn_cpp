/*
https://leetcode.com/problems/longest-palindromic-substring/description/?envType=problem-list-v2&envId=dynamic-programming&difficulty=MEDIUM
*/

#include <bits/stdc++.h>
#include <string>
using namespace std;


class PalindromicString {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";

        // Create a 2D DP table to store whether substring s[i:j] is a palindrome.
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int maxLength = 1;  // The length of the longest palindrome found
        int start = 0;      // The starting index of the longest palindrome

        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Check for palindromes of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        // Check for palindromes of length greater than 2
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;  // Ending index of the current substring

                // Check if s[i:j] is a palindrome
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;

                    if (len > maxLength) {
                        start = i;
                        maxLength = len;
                    }
                }
            }
        }

        // Return the longest palindrome substring
        return s.substr(start, maxLength);
    }

};
class PalindromicStringSlowSolution {
public:
    string longestPalindrome(string s) {

        unordered_map<char, vector<int>> mapOccurance = generateMapOfOccurrance(s);
        printMapOfOccurrance(mapOccurance);
    
        string result = "";
        for (auto ch : mapOccurance){
            vector<int>& listOccur = ch.second;
            if(listOccur.size() > 1) {
                for(uint start=0; start < listOccur.size()-1; start++) {
                    for(uint end = start+1; end < listOccur.size(); end++ ) {
                        string subString = s.substr(listOccur.at(start), listOccur.at(end) - listOccur.at(start) + 1);
                        if ( isPalindromeString(subString)) {
                            if (subString.length() > result.length()){
                                result = subString;
                            }
                        }
                    }
                }
            }
            else if (listOccur.size() == 1 && result.empty()) {
                result = ch.first;
            }
        }
        return result;
    }

    bool isPalindromeString(string s) {
        int size = s.length();
        for (int i = 0; i <= size/2; i++) {
            if (s[i] != s[size - i - 1]){
                return false;
            }
        }
        return true;
    }

    unordered_map<char, vector<int>> generateMapOfOccurrance(const string& s){
        unordered_map<char, vector<int>> m;
        for (uint i = 0; i < s.length(); i++) {
            if (m.find(s.at(i)) == m.end()){
                // m[s.at(i)] = vector<int>{};
                m.insert(std::pair<char, vector<int>>{s.at(i), vector<int>{}});
            }
            m[s.at(i)].push_back(i);
        }

        return m;
    }

    void printMapOfOccurrance(unordered_map<char, vector<int>>&& m) {
        for (auto& ch : m){
            std::cout << ch.first << ":";
            std::cout << "[";
            for (auto& occur : ch.second){
                std::cout << occur << " ";
            } 
            std::cout << "]" << std::endl;
        }
    }

    void printMapOfOccurrance(unordered_map<char, vector<int>>& m) {
        printMapOfOccurrance(std::move(m));
    }
};