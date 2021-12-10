// https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *list = new ListNode;
        if (list1 == nullptr) { return list2; }
        if (list2 == nullptr) { return list1; }
        if (list1->val <= list2->val) {
            list->val = list1->val;
            list->next = mergeTwoLists(list1->next, list2);
        } else {
            list->val = list2->val;
            list->next = mergeTwoLists(list1, list2->next);
        }
        return list;
    }
};

int main() {
    
    return 0;
}