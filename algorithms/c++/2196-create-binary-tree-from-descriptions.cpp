// https://leetcode.com/problems/create-binary-tree-from-descriptions/
#include <bits/stdc++.h>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_map<TreeNode*, TreeNode*> parentmp;
        
        for (int i = 0; i < descriptions.size(); i++) {
            int val = descriptions[i][0];
            int childval = descriptions[i][1];
            
            TreeNode* node = mp.count(val) ? mp[val] : mp[val] = new TreeNode(val);
            TreeNode* child = mp.count(childval) ? mp[childval] : mp[childval] = new TreeNode(childval);
            
            if (descriptions[i][2])
                node->left = child;
            else
                node->right = child;
            
            parentmp[child] = node;
        }
        auto root = parentmp.begin()->second;
        while(parentmp.count(root))
            root = parentmp[root];
        return root;
    }
};

int main() {

    return 0;
}