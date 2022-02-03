// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root || !root->left && !root->right) return root;
        Node* leftmost = root;
        while(leftmost) {
            Node* curr = leftmost;
            Node* prev = nullptr;
            while(curr) {
                if (curr->left) {
                    if (prev) {
                        prev->next = curr->left;
                    }
                    prev = curr->left;
                }
                if (curr->right) {
                    if (prev) {
                        prev->next = curr->right;
                    }
                    prev = curr->right;
                }
                curr = curr->next;
            }
            
            while(leftmost && !leftmost->left && !leftmost->right) {
                leftmost = leftmost->next;
            }
            if (leftmost)
                leftmost = leftmost->left ? leftmost->left : leftmost->right;
        }
        return root;
    }
};

int main() {

    return 0;
}