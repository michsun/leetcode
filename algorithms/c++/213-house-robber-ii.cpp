// https://leetcode.com/problems/house-robber-ii/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        vector<int> dp(n-1,0);
        dp[0] = nums[0];
        dp[1] = max(nums[1], dp[0]);
        int sol1 = dp[1];
        for (int i = 2; i < n-1; i++) {
            sol1 = max(sol1, nums[i]+dp[i-2]);
            dp[i] = sol1;
        }
        
        dp[0] = nums[1];
        dp[1] = max(nums[2], dp[0]);
        int sol2 = dp[1];
        for (int i = 2; i < n-1; i++) {
            sol2 = max(sol2, nums[i+1]+dp[i-2]);
            dp[i] = sol2;
        }
        
        return max(sol1, sol2);
    }
};

int main() {

    return 0;
}