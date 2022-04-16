// https://leetcode.com/problems/convert-bst-to-greater-tree/
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
};

class Solution {
public:
    void traverse(TreeNode* root, int& total) {
        if (root) {
            if (root->right) {
                traverse(root->right, total);
            }
            root->val += total;
            total = root->val;
            if (root->left) {
                traverse(root->left, total);
            }
        }
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int total = 0;
        traverse(root, total);
        return root;
    }
};

int main() {

    return 0;
}