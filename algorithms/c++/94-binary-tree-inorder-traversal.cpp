// https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    void inorderTraversal(TreeNode* root, vector<int>& vec) {
        if (root->left != nullptr) inorderTraversal(root->left, vec);
        vec.push_back(root->val);
        if (root->right != nullptr) inorderTraversal(root->right, vec);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;
        if (!root) return traversal;
        inorderTraversal(root, traversal);
        return traversal;
    }
};

int main() {

    return 0;
}