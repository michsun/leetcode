// https://leetcode.com/problems/binary-tree-preorder-traversal/
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
    // Recursive solution
    void preorderTraversal(TreeNode* root, vector<int>& traversal) {
        if (!root) return;
        traversal.push_back(root->val);
        
        if (root->left != nullptr) {
            preorderTraversal(root->left, traversal);
        }
        if (root->right != nullptr) {
            preorderTraversal(root->right, traversal);
        }
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> traversal;
        if (!root) return traversal;
        preorderTraversal(root, traversal);
        return traversal;
    }
};

int main() {

    return 0;
}