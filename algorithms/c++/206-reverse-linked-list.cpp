// https://leetcode.com/problems/reverse-linked-list/
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
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = nullptr;
        while(head != nullptr) {
            ListNode* temp = newHead;
            newHead = head;
            head = head->next;
            newHead->next = temp;
        }
        return newHead;
    }
};

int main() {

    return 0;
}