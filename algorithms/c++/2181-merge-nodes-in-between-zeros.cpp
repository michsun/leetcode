// https://leetcode.com/problems/merge-nodes-in-between-zeros/
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* front = new ListNode();
        ListNode* curr = front;
        
        while(head->next) {
            ListNode* start = head;
            int sum = 0;
            while(head->next->val != 0) {
                sum += head->next->val;
                head = head->next;
            }
            head = head->next;
            curr->next = new ListNode(sum);
            curr = curr->next;
        }
        
        return front->next;
    }
};

int main() {

    return 0;
}