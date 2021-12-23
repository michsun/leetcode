// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) { // swap node variables ensuring p->val < q->val
            TreeNode* temp = q;
            q = p;
            p = temp;
        }
        TreeNode* curr = root;
        while(curr != nullptr) {
            if (curr->val >= p->val && curr->val <= q->val) return curr;
            if (curr->val > q->val) curr = curr->left;
            if (curr->val < p->val) curr = curr->right;
        }
        return curr;
    }
};

int main() {

    return 0;
}