/*
98. Validate Binary Search Tree
*/

#include "common.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class ValidateBinarySearchTreeSolution {
private:
    const bool side_left{0};
    const bool side_right{1};

    void dfs(TreeNode* node, const vector<int>& list_greater, const vector<int>& list_smaller, bool& valid) {
        if (!node) return;
        if (!valid) return;

        /*
            node->val is expected to greater than every items in list_smaller
            node->val is expected to smaller than every items in list_greater
        */
       if  (find_if(list_greater.begin(), list_greater.end(), 
                    [=](const int& val){ 
                        return (val <= node->val);
                    }
                ) != list_greater.end()
            ) 
            {
                valid = false;
            }
        
        if  (find_if(list_smaller.begin(), list_smaller.end(), 
                    [=](const int& val){ 
                        return (val >= node->val);
                    }
                ) != list_smaller.end()
            ) 
            {
                valid = false;
            }
        if (!valid) return;

        vector<int> list_greater_new{list_greater};
        vector<int> list_smaller_new{list_smaller};
        list_greater_new.push_back(node->val);
        list_smaller_new.push_back(node->val);
        dfs(node->left, list_greater_new, list_smaller, valid);
        dfs(node->right, list_greater, list_smaller_new, valid);
    }

public:
    bool isValidBST(TreeNode* root) {
        bool valid{true};
        vector<int> list_greater_l;
        vector<int> list_smaller_l;
        vector<int> list_greater_r;
        vector<int> list_smaller_r;

        list_greater_l.push_back(root->val);
        list_smaller_r.push_back(root->val);
        dfs(root->left,  list_greater_l, vector<int>(), valid);
        dfs(root->right, vector<int>(), list_smaller_r, valid);
        return valid;
    }
};