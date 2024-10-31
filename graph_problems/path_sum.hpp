/*
113. Path Sum II
Given the root of a binary tree and an integer targetSum, 
return all root-to-leaf paths where the sum of the node values in the path equals targetSum. 
Each path should be returned as a list of the node values, not node references.
*/

#include <vector>
#include <iostream>
#include "common.hpp"

using namespace std;

class DFSPathSumSolution {
private:
    void dfs(TreeNode* node, int targetSum, vector<int>& v, vector<vector<int>>& res) {
        // if this is leaf
        if (!node) return;

        if (!node->left && !node->right) {
            if (targetSum == node->val) {
                v.push_back(node->val);
                res.push_back(v);
            }
        } else {
            v.push_back(node->val);

            vector<int> v_left{v};
            vector<int> v_right{v};
            dfs(node->left, targetSum - node->val, v_left, res);
            dfs(node->right, targetSum - node->val, v_right, res);
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> v; 
        dfs(root,targetSum, v, res);
        return res;
    }
};