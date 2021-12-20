// https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
    // BFS approach
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int maxDepth = 0;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            maxDepth++;
            int n = q.size();
            while(n > 0) {
                TreeNode* curr = q.front();
                q.pop();
                
                if (curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
                n--;
            }
        }
        return maxDepth;
    }
};

int main() {

    return 0;
}