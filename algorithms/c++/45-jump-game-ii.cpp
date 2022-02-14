// https://leetcode.com/problems/jump-game-ii/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n-1; i++) {
            if (i == 0 || (i > 0 && dp[i] > 0)) {
                for (int j = 1; j <= nums[i] && j < n-i; j++) {
                    dp[i+j] = dp[i+j] > 0 ? min(dp[i+j], dp[i]+1) : dp[i]+1;
                }
            }
        }
        return dp[n-1];
    }
};

int main() {

    return 0;
}