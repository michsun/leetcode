// https://leetcode.com/problems/sort-list/
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
    ListNode* getMid(ListNode* node) {
        ListNode* prev = nullptr;
        while(node && node->next) {
            prev = (prev == nullptr) ? node : prev->next;
            node = node->next->next;
        }
        ListNode* mid = prev->next;
        prev->next = nullptr;
        return mid;
    }
    
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* front = new ListNode(); // dummy head
        ListNode* ptr = front;
        
        while(left && right) {
            if (left->val <= right->val) {
                ptr->next = left;
                left = left->next;
            } else {
                ptr->next = right;
                right = right->next;
            }
            ptr = ptr->next;
        }
        
        while(left) {
            ptr->next = left;
            left = left->next;
            ptr = ptr->next;
        }
        while(right) {
            ptr->next = right;
            right = right->next;
            ptr = ptr->next;
        }
        return front->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    }
};

int main() {

    return 0;
}