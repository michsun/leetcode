// https://leetcode.com/problems/linked-list-cycle-ii/
#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // Floyd's Algorithm solution
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode* seek = head;
                while(seek != slow) {
                    seek = seek->next;
                    slow = slow->next;
                }
                return seek;
            }
        }
        return NULL;
    }
    
    // Hashing solution
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> dp;
        ListNode* curr = head;
        while(curr) {
            if (dp.find(curr) != dp.end())
                return curr;
            dp.insert(curr);
            curr = curr->next;
        }
        return NULL;
    }
};

int main() {

    return 0;
}