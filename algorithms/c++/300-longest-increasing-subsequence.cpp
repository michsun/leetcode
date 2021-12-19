// https://leetcode.com/problems/longest-increasing-subsequence/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Dynamic programming solution
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        vector<int> dp(nums.size(), 1);
        int largest = 1;
        for (int j = 1; j < nums.size(); j++) {
            for (int i = 0; i < j; i++) {
                if (nums[j] > nums[i]) {
                    if (dp[i] + 1 > dp[j]) {
                        dp[j] = dp[i] + 1;
                    }
                }
            }
            largest = max(largest, dp[j]);
        }
        return largest;
    }
};

int main() {

    return 0;
}