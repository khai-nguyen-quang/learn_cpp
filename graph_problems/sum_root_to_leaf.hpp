
/*
129. Sum Root to Leaf Numbers
https://leetcode.com/problems/sum-root-to-leaf-numbers/description/?envType=problem-list-v2&envId=depth-first-search&difficulty=MEDIUM
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <iostream>
#include "common.hpp"

using namespace std;

class SumRoot2LeafSolution {
private:
    void dfs(TreeNode* node, int& cur_sum, int& final_sum) {
        if (!node) return;

        // Reach a leaf
        if (!node->left && !node->right) {
            cur_sum = cur_sum * 10 + node->val;
            final_sum += cur_sum;
        } else {
            cur_sum = cur_sum * 10 + node->val;
            int cur_sum_left{cur_sum}, cur_sum_right{cur_sum};
            dfs(node->left, cur_sum_left, final_sum);
            dfs(node->right, cur_sum_right, final_sum);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        int curr_sum{0};
        int final_sum{0};
        dfs(root, curr_sum, final_sum);

        return final_sum;
    }
};