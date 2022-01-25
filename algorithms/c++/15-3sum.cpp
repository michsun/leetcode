// https://leetcode.com/problems/3sum/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sol;
        if (nums.size() < 3) return sol;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for (int i = 0; i < n-2; i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int p = i+1, q = n-1;
            while(p < q) {
                int sum = nums[i] + nums[p] + nums[q];
                if (sum ==  0) {
                    sol.push_back({nums[i], nums[p], nums[q]});
                    while(p < n-1 && nums[p] == nums[p+1]) p++;
                    while(q > i && nums[q] == nums[q-1]) q--;
                    p++; q--;
                } else if (sum < 0) {
                    p++;
                } else {
                    q--;
                }
            }
        }
        return sol;
    }
};

int main() {

    return 0;
}