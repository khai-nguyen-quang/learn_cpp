/*
98. Validate Binary Search Tree
*/

#include "common.hpp"
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
class ValidateBinarySearchTreeSolution {
private:
    const bool side_left{0};
    const bool side_right{1};

    void dfs(TreeNode* node, set<int>& list_greater, set<int>& list_smaller, bool& valid) {
        if (!node) return;
        if (!valid) return;

        /*
            node->val is expected to greater than every items in list_smaller
            node->val is expected to smaller than every items in list_greater
        */
        if (!list_greater.empty()){
            valid = valid && node->val < *list_greater.begin();
        }
        if (!list_smaller.empty()) {
            valid = valid && node->val > *list_smaller.rbegin();
        }
        if (!valid) return;

        if (node->left) {
            list_greater.insert(node->val);
            dfs(node->left, list_greater, list_smaller, valid);
            list_greater.erase(node->val);
            if (!valid) return;
        }
        if (node->right){
            list_smaller.insert(node->val);
            dfs(node->right, list_greater, list_smaller, valid);
            list_smaller.erase(node->val);
            if (!valid) return;
        }   
    }

public:
    bool isValidBST(TreeNode* root) {
        bool valid{true};
        set<int> list_greater_l;
        set<int> list_smaller_l;
        set<int> list_greater_r;
        set<int> list_smaller_r;

        list_greater_l.insert(root->val);
        list_smaller_r.insert(root->val);
        dfs(root->left,  list_greater_l, list_smaller_l, valid);
        dfs(root->right, list_greater_r, list_smaller_r, valid);
        return valid;
    }
};