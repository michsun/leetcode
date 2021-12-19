// https://leetcode.com/problems/binary-tree-postorder-traversal/
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
    void postorderTraversal(TreeNode* root, vector<int>& vec) {
        if (root->left) postorderTraversal(root->left, vec);
        if (root->right) postorderTraversal(root->right, vec);
        vec.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> traversal;
        if (!root) return traversal;
        postorderTraversal(root, traversal);
        return traversal;
    }
};

int main() {

    return 0;
}