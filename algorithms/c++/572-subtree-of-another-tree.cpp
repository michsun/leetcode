// https://leetcode.com/problems/subtree-of-another-tree/
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
    bool checkSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root || !subRoot) {
            if (root == nullptr && subRoot == nullptr)
                return true;
            return false;
        }
        if (root->val != subRoot->val)
            return false;
        return checkSubtree(root->left, subRoot->left) && checkSubtree(root->right, subRoot->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root->val == subRoot->val) {
            if (checkSubtree(root, subRoot))
                return true;
        }
        return (root->left && isSubtree(root->left, subRoot)) || (root->right && isSubtree(root->right, subRoot));
    }
};

int main() {

    return 0;
}