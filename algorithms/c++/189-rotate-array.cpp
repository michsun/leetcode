// https://leetcode.com/problems/rotate-array/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        for (int i = 0; i < (k/2); i++)
            swap(nums[i], nums[k-1-i]);
        
        for (int i = k; i < k+(n-k)/2; i++)
            swap(nums[i], nums[n-(i-k)-1]);
    }
};

int main() {

    return 0;
}