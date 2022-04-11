// https://leetcode.com/problems/kth-largest-element-in-a-stream/
#include <bits/stdc++.h>

using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
    
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto& e : nums) 
            this->minHeap.push(e);
        while(minHeap.size() > k)
            this->minHeap.pop();
    }
    
    int add(int val) {
        if (minHeap.size() < k) {
            minHeap.push(val);
        } else if (val > minHeap.top()) {
            minHeap.push(val);
            minHeap.pop();
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main() {

    return 0;
}