// https://leetcode.com/problems/subsets/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>> &sol, vector<int>& subset, int n, int j) {
        sol.push_back(subset);
        for (int i = j; i < n; i++) {
            subset.push_back(nums[i]);
            backtrack(nums, sol, subset, n, i+1);
            subset.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> subset;
        int n = nums.size();
        backtrack(nums, sol, subset, n, 0);
        return sol;
    }
};

int main() {

    return 0;
}