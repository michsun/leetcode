// https://leetcode.com/problems/search-in-a-binary-search-tree/
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return NULL;
        if (root->val == val) return root;
        TreeNode* node = root->val > val ? searchBST(root->left, val) : searchBST(root->right, val);
        return node;
    }
    
    // Iterative solution
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL && root->val != val) {
            root = root->val > val ? root->left : root->right;
        }
        return root;
    }
};

int main() {

    return 0;
}