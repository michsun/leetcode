// https://leetcode.com/problems/reorder-list/
#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Solution 1 - Stack
    void reorderList(ListNode* head) {
        if (head->next == nullptr || head->next->next == nullptr) return;
        
        stack<ListNode*> stk;
        ListNode* curr = head;
        while(curr) { // Add all nodes to a stack
            stk.push(curr);
            curr = curr->next;
        }
        
        int n = stk.size();
        for (int i = 0; i < n/2; i++) {
            ListNode* node = stk.top();
            stk.pop();
            node->next = head->next;
            head->next = node;
            head = head->next->next; // node->next
        }
        head->next = nullptr;
    }
    
    // Solution 2 - Array pointer
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        
        ListNode* curr = head;
        while(curr != nullptr) {
            nodes.push_back(curr);
            curr = curr->next;
        }
        
        ListNode* prev = head;
        int p = 1;
        int q = nodes.size()-1;
        while(p <= q) {
            prev->next = nodes[q];
            prev = nodes[q];
            prev->next = nullptr;
            --q;
            if (p <= q) {
                prev->next = nodes[p];
                prev = nodes[p];
                prev->next = nullptr;
            }
            ++p;
        }
    }
};

int main() {

    return 0;
}