// https://leetcode.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        ListNode* curr = nullptr;
        int carryOver = 0;
        
        while(l1 || l2) {
            int sum = carryOver;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carryOver = sum/10;
            
            if (curr == nullptr) {
                curr = new ListNode(sum%10);
                result = curr;
            } else {
                curr->next = new ListNode(sum%10);
                curr = curr->next;
            }
        }
        if (carryOver)
            curr->next = new ListNode(carryOver);
        
        return result;
    }
};

int main() {

    return 0;
}