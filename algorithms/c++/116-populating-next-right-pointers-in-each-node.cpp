// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
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
    // Solution without additional space
    Node* connect(Node* root) {
        Node *leftMost = root, *curr;
        while(leftMost) {
            curr = leftMost;
            while(curr && curr->left) {
                curr->left->next = curr->right;
                if (curr->next) {
                    curr->right->next = curr->next->left;
                }
                curr = curr->next;
            }
            leftMost = leftMost->left;
        }
        return root;
    }

    // Solution utilising queues
    Node* connect(Node* root) {
        if (root == NULL) return root;
        queue<Node*> currQueue;
        queue<Node*> nextQueue;
        Node* nextRight = NULL;
        currQueue.push(root);
        
        while(!currQueue.empty() || !nextQueue.empty()) {
            while(!currQueue.empty()) {
                Node* curr = currQueue.front();
                currQueue.pop();
                curr->next = nextRight;
                nextRight = curr;
                
                if (curr->right) nextQueue.push(curr->right);
                if (curr->left) nextQueue.push(curr->left);
            }
            while(!nextQueue.empty()) {
                currQueue.push(nextQueue.front());
                nextQueue.pop();
            }
            nextRight = NULL;
        }
        return root;
    }
};

int main() {

    return 0;
}