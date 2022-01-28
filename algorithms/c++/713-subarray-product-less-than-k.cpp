// https://leetcode.com/problems/subarray-product-less-than-k/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        
        int front = 0;
        int product = 1;
        for (int i = 0; i < n; i++) {
            product *= nums[i];
            while(product >= k && front < i) {
                product /= nums[front];
                front++;
            }
            if (product < k)
                count += (i-front)+1;
        }
        return count;
    }
};

int main() {

    return 0;
}