// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
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
    void dfs(TreeNode* node, int& sum, int currSum) {
        currSum *= 2;
        if (!node->left && !node->right) { 
            sum += currSum + node->val;
            return;
        }
        if (node->left) dfs(node->left, sum, currSum+node->val);
        if (node->right) dfs(node->right, sum, currSum+node->val);
        return;
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        dfs(root, sum, 0);
        return sum;
    }
};

int main() {

    return 0;
}