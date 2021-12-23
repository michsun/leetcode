// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
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
    bool findTargetDFS(TreeNode* node, unordered_set<int>& hashset, int k) {
        if (!node) return false;
        if (hashset.count(k - node->val)) return true;
        hashset.insert(node->val);
        return findTargetDFS(node->left, hashset, k) || findTargetDFS(node->right, hashset, k);
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> hashset;
        return findTargetDFS(root, hashset, k);
    }
};

int main() {

    return 0;
}