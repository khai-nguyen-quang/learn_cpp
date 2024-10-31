#include "graph_problems/path_sum.hpp"
#include "graph_problems/sum_root_to_leaf.hpp"

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

void main_graph(){
    // test_path_sum();
    test_sum_root_to_leaf_number();
}