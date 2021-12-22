// https://leetcode.com/problems/insert-into-a-binary-search-tree/
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }
        if (root->val > val) root->left = insertIntoBST(root->left, val);
        if (root->val < val) root->right = insertIntoBST(root->right, val);
        return root;
    }
    
    // Iterative solution
    TreeNode* insertIntoBST2(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if (!root) return newNode;
        
        TreeNode* prev = root;
        while(prev != NULL) {
            if (prev->val > val) {
                if (prev->left == nullptr) {
                    prev->left = newNode;
                    prev = NULL;
                } else {
                    prev = prev->left;
                }
            } else if (prev->val < val) {
                if (prev->right == nullptr) {
                    prev->right = newNode;
                    prev = NULL;
                } else {
                    prev = prev->right;
                }
            }
        }
        return root;
    }
};

int main() {

    return 0;
}