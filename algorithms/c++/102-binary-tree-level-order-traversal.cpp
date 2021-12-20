// https://leetcode.com/problems/binary-tree-level-order-traversal/
#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}

class Solution {
public:
    void levelOrder(vector<TreeNode*>& currLevel, vector<vector<int>>& traversal) {
        if (currLevel.empty()) return;
        
        vector<int> level;
        vector<TreeNode*> nextLevel;
        for (auto node: currLevel) {
            level.push_back(node->val);
            if (node->left != nullptr) nextLevel.push_back(node->left);
            if (node->right != nullptr) nextLevel.push_back(node->right);
        }
        traversal.push_back(level);
        levelOrder(nextLevel, traversal);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> sol;
        if (!root) return sol;
        
        vector<TreeNode*> level = { root };
        levelOrder(level, sol);
        return sol;
    }
};

int main() {

    return 0;
}