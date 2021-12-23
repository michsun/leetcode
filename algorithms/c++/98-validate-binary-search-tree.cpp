// https://leetcode.com/problems/validate-binary-search-tree/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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
    bool isValidBST(TreeNode* node, pair<ll,ll> boundary) {
        if (!node) return true;
        if (node->val <= boundary.first || node->val >= boundary.second) return false;
        return isValidBST(node->left, make_pair(boundary.first, (ll)node->val)) && isValidBST(node->right, make_pair( (ll) node->val, boundary.second));
    }
    
    bool isValidBST(TreeNode* root) {
        pair<ll, ll> initialBoundaries = make_pair( -(ll)pow(2,31)-1, (ll)pow(2,31)+1);
        return isValidBST(root, initialBoundaries);
    }
};

int main() {
    
    return 0;
}