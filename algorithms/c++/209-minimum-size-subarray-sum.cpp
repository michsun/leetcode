// https://leetcode.com/problems/minimum-size-subarray-sum/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sol = INT_MAX;
        int i = 0, sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            while (sum > target && i < j && sum - nums[i] >= target) 
                sum -= nums[i++];
            if (sum >= target) 
                sol = min(sol, j-i+1);
        }
        return (sol == INT_MAX) ? 0 : sol;
    }
};

int main() {

    return 0;
}