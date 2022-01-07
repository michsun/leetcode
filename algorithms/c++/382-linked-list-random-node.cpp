// https://leetcode.com/problems/linked-list-random-node/
#include <bits/stdc++.h>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* head;
    
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        ListNode* curr = this->head;
        int sol = curr->val;
        int i = 0;
        while(curr) {
            i++;
            if (rand() % i == 0)
                sol = curr->val;
            curr = curr->next;
        }
        return sol;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

int main() {

    return 0;
}