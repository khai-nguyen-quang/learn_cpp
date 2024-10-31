#include "graph_problems/path_sum.hpp"

using namespace std;

void main_graph(){
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