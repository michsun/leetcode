// https://leetcode.com/problems/path-sum/
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
    bool hasPathSum(TreeNode* node, int targetSum, int currSum) {
        if (!node) return false;
        currSum += node->val;
        if (currSum == targetSum && node->left == nullptr && node->right == nullptr) return true;
        return hasPathSum(node->left, targetSum, currSum) || hasPathSum(node->right, targetSum, currSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return hasPathSum(root, targetSum, 0);
    }
};

int main() {

    return 0;
}