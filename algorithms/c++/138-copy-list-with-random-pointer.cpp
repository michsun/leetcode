// https://leetcode.com/problems/copy-list-with-random-pointer/
#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodeMap;
        Node* front = new Node(-1);
        Node* prev = front;
        while(head) {
            Node* curr = (nodeMap.find(head) != nodeMap.end()) ? nodeMap[head] : nodeMap[head] = new Node(head->val);
            if (head->random) {
                if (nodeMap.find(head->random) == nodeMap.end()) {
                    nodeMap[head->random] = new Node(head->random->val);  
                }
                curr->random = nodeMap[head->random];
            }
            head = head->next;
            prev->next = curr;
            prev = prev->next;
        }
        return front->next;
    }
};

int main() {

    return 0;
}