// https://leetcode.com/problems/merge-two-binary-trees/
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
    TreeNode* mergeTrees(TreeNode* newNode, TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr)
            return node2;
        if (node2 == nullptr)
            return node1;
        newNode->val = node1->val + node2->val;
        
        newNode->right = mergeTrees(newNode->right, node1->right, node2->right);
        newNode->left = mergeTrees(newNode->left, node1->left, node2->left);
        
        return newNode;
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* newHead = mergeTrees(root1, root1, root2);
        return newHead;
    }
};

int main() {

    return 0;
}