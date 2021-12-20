// https://leetcode.com/problems/symmetric-tree/
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
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> s1, s2;
        s1.push(root->left);
        s2.push(root->right);
        
        while(!s1.empty() && !s2.empty()) {
            TreeNode* left = s1.top();
            s1.pop();
            TreeNode* right = s2.top();
            s2.pop();
            
            if (left == nullptr && right == nullptr)
                continue;
            if (left == nullptr || right == nullptr)
                return false;
            if (left->val != right->val)
                return false;
            s1.push(left->right);
            s1.push(left->left);
            s2.push(right->left);
            s2.push(right->right);
        }
        return true;
    }
};

int main() {

    return 0;
}