// https://leetcode.com/problems/middle-of-the-linked-list/
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
    ListNode* middleNode(ListNode* head) {
        ListNode* middle = head;
        int cnt = 0;
        while(head->next) {
            cnt++;
            head = head->next;
            if (cnt%2 == 0)
                middle = middle->next;
        }
        if (cnt%2 == 1)
            return middle->next;
        return middle;
    }
};

int main() {

    return 0;
}