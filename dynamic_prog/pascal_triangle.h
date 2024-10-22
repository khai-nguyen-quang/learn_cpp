
/*
https://leetcode.com/problems/pascals-triangle/?envType=problem-list-v2&envId=dynamic-programming&difficulty=EASY
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class PascalTriangle {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        v.reserve(numRows);
        for (int  i = 0; i < numRows; i++){
            vector<int> row (i+1);
            v.push_back(row);
        }
        generate(numRows -1 , v);

        return v;
    }

private:
    void generate(int rowIndx, vector<vector<int>>& memo) {
        if (rowIndx == 0) {
            memo.at(0) = {1};
        } else if (rowIndx == 1) {
            memo.at(0) = {1};
            memo.at(1) = {1,1};
        } else {
            generate(rowIndx - 1, memo);

            vector<int>& prevRow = memo.at(rowIndx-1);
            vector<int>& curRow = memo.at(rowIndx);
            curRow.at(0) = 1;
            curRow.at(curRow.size() - 1) = 1;
            for (uint index=1; index < curRow.size() -1; index++){
                curRow.at(index) = prevRow.at(index-1) + prevRow.at(index);
            }
        }
    }
};