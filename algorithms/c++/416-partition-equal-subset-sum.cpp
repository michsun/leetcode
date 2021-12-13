// https://leetcode.com/problems/partition-equal-subset-sum/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool subsetSum(vector<int>& nums, int& n, int& sum) {
        vector<vector<bool>> mem(n+1, vector<bool>(sum+1, false));
        
        for (int i = 0; i <= n; i++) {
            mem[i][0] = true;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (j < nums[i-1]) {
                    mem[i][j] = mem[i-1][j];
                } else {
                    mem[i][j] = mem[i-1][j-nums[i-1]] || mem[i-1][j];
                }
            }
        }
        
        return mem[n][sum];
    }
    
    bool canPartition(vector<int>& nums) {
        if (nums.size() <= 1) return false;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        
        int n = nums.size();
        return subsetSum(nums, n, target);
    }
};

int main() {

    return 0;
}