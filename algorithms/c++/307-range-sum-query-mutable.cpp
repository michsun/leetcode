// https://leetcode.com/problems/range-sum-query-mutable/
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    int start;
    int end;
    Node *left;
    Node *right;
};

class NumArray {
public:
    Node *root;
    vector<int> nums;
    int size;
    
    NumArray(vector<int>& nums) {
        this->nums = nums;
        size = nums.size();
        root = buildTree(0, size-1);
    }
    
    Node* buildTree(int start, int end) {
        if (start > end) return nullptr;
        
        Node* node = new Node();
        node->start = start;
        node->end = end;
        if (start == end) {
            node->val = nums[start];
        } else {
            int mid = (start + end) / 2;
            node->left = buildTree(start, mid);
            node->right = buildTree(mid+1, end);
            node->val = node->left->val + node->right->val;
        }
        return node;
    }
    
    void update(int index, int val) {
        updateTree(root, index, val);
        nums[index] = val;
    }
    
    void updateTree(Node* node, int index, int val) {
        if (node->start == node->end) {
            node->val = val;
            return;
        }
        int mid = (node->start + node->end)/2;
        if (index <= mid)
            updateTree(node->left, index, val);
        else
            updateTree(node->right, index, val);
        
        node->val = node->left->val + node->right->val;
    }
    
    int sumRange(int left, int right) {
        return sumNodes(root, left, right);
    }
    
    int sumNodes(Node* node, int start, int end) {
        if (node->start == start && node->end == end) return node->val;
        int mid = (node->start + node->end)/2;
        if (mid >= end)
            return sumNodes(node->left, start, end);
        else if (mid < start)
            return sumNodes(node->right, start, end);
        else
            return sumNodes(node->left, start, mid) + sumNodes(node->right, mid+1, end);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main() {
    
    return 0;
}