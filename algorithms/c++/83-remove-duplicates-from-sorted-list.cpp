// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        
        ListNode* newHead = new ListNode();
        ListNode* p = head;
        newHead->next = p;
        ListNode* q = head->next;
        
        while(q != nullptr) {
            if (p->val != q->val) {
                p->next = q;
                p = p->next;
            }  
            q = q->next;
        }
        p->next = nullptr;
        return newHead->next;
    }
};

int main() {

    return 0;
}