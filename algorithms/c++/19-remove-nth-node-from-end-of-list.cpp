// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* toRemove = head;
        ListNode* curr = head;
        
        while(n-- > 0) {
            curr = curr->next;
        }
        if (curr == nullptr) return head->next;
        
        while(curr->next) {
            curr = curr->next;
            toRemove = toRemove->next;
        }
        toRemove->next = toRemove->next->next;
        
        return head;
    }
};

int main() {

    return 0;
}