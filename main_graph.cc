#include "graph_problems/path_sum.hpp"
#include "graph_problems/sum_root_to_leaf.hpp"
#include "graph_problems/validate_binary_search_tree.hpp"

using namespace std;

void test_path_sum() {
    TreeNode node_l_7(7), node_l_2(2), node_l_11(11, &node_l_7, &node_l_2), node_l_4(4, &node_l_11, nullptr);
    TreeNode node_r_5(5), node_r_1(1), node_r_4(4, &node_r_5, &node_r_1), node_r_13(13), node_r_8(8, &node_r_13, &node_r_4);
    TreeNode root(5, &node_l_4, &node_r_8);

    DFSPathSumSolution dfs_path_sum{};
    vector<vector<int>> res = dfs_path_sum.pathSum(&root, 22);
    for(vector<int>& v : res) {
        cout << "[";
        for (int i : v) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << endl;
}

void test_sum_root_to_leaf_number(){
    TreeNode node5(5),node1(1);
    TreeNode node9(9, &node5, &node1);
    TreeNode node0(0);
    TreeNode root(4, &node9, &node0);

    SumRoot2LeafSolution sol{};
    cout << sol.sumNumbers(&root) << endl;

}

void test_validate_binary_search_tree() {
    ValidateBinarySearchTreeSolution sol{};
    /*
    [2,1,3] --> true
            2
        1      3
    */
    // TreeNode node1(1), node3(3), node6(6);
    // TreeNode root2(2, &node1, &node3);
    // cout << boolalpha << sol.isValidBST(&root2) << endl;

    /*
    [5,1,4,nul,nul,3,6] --> false
              5
         1        4
       n   n   3    6
    */
    // TreeNode node4(4, &node3, &node6);
    // TreeNode root5(5, &node1, &node4);
    // cout << boolalpha << sol.isValidBST(&root5) << endl;

    /* 
    [3,1,5,0,2,4,6] --> true
              3
          1      5
        0   2   4  6
    */
    // TreeNode node0(0), node2(2), node4(4), node6(6);
    // TreeNode node1(1, &node0, &node2), node5(5, &node4,&node6);
    // TreeNode root(3, &node1, &node5);
    // cout << boolalpha <<sol.isValidBST(&root) << endl;

    /*
    [5,4,6,null,null,3,7] --> false
            5
         4     6
             3   7
    */
    // TreeNode node3(3), node7(7); 
    // TreeNode node4(4), node6(6, &node3,&node7);
    // TreeNode root(5, &node4, &node6);
    // cout << boolalpha <<sol.isValidBST(&root) << endl;

    /* [32,26,47,19,null,null,56,null,27] --> false
                    32
                26      47
            19    n   n    56
          n    27  
    */
    // TreeNode node27(27), node56(56);
    // TreeNode node19(19, nullptr, &node27);
    // TreeNode node26(26, &node19, nullptr);
    // TreeNode node47(47, nullptr, &node56);
    // TreeNode root(32, &node26, &node47);
    // cout << boolalpha <<sol.isValidBST(&root) << endl;

}

void main_graph(){
    // test_path_sum();
    // test_sum_root_to_leaf_number();
    // test_validate_binary_search_tree();
}