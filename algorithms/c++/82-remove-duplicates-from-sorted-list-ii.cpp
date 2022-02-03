// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
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
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* start = new ListNode(-101);
        ListNode* prev = start;
        
        while(head) {
            if (head->next && head->val == head->next->val) {
                while (head->next && head->val == head->next->val)
                    head = head->next;
                prev->next = head->next;
            } else {
                prev->next = head;
                prev = prev->next;
            }
            head = head->next;
        }
        
        return start->next; 
    }
};

int main() {

    return 0;
}