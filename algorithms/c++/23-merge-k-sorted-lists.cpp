// https://leetcode.com/problems/merge-k-sorted-lists/
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
    // Compare one by one solution; compares the heads of each list
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* front = new ListNode();
        ListNode* curr = front;
        
        stack<int> lltoRemove;
        int smallest, smallestPos;
        while(lists.size() != 0) {
            smallest = INT_MAX;
            smallestPos = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] == nullptr) {
                    lltoRemove.push(i);
                    continue;
                }
                if (lists[i]->val < smallest) {
                    smallest = lists[i]->val;
                    smallestPos = i;
                }
            }
            if (smallestPos != -1) {
                curr->next = lists[smallestPos];
                lists[smallestPos] = lists[smallestPos]->next;
                curr = curr->next;
            }
            while(!lltoRemove.empty()) {
                int pos = lltoRemove.top();
                lists.erase(lists.begin() + pos);
                lltoRemove.pop();
            }
        }
        return front->next;
    }
};

int main() {

    return 0;
}