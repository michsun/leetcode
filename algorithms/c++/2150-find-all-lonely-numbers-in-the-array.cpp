// https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums;
        vector<int> sol;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; i++) {
            int before = i-1;
            int after = i+1;
            if (i == 0) {
                if (nums[after] - nums[i] > 1)
                    sol.push_back(nums[i]);
                continue;
            }
            if (i == n-1) {
                if (nums[i] - nums[before] > 1)
                    sol.push_back(nums[i]);
                continue;
            }
            
            if ( nums[after] - nums[i] > 1 && nums[i] - nums[before] > 1)
                sol.push_back(nums[i]);
        }
        return sol;
    }
};

int main() {

    return 0;
}