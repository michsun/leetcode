// https://leetcode.com/problems/permutations/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int>>&sol, vector<int>& nums, int& n, vector<int> permutation, vector<int> selected) {
        if (permutation.size() == n) {
            sol.push_back(permutation);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (selected[i]) continue;
            selected[i] = 1;
            permutation.push_back(nums[i]);
            backtrack(sol, nums, n, permutation, selected);
            permutation.pop_back();
            selected[i] = 0;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> sol;
        int n = nums.size();
        vector<int> selected(n, 0);
        vector<int> permutation;
        backtrack(sol, nums, n, permutation, selected);
        return sol;
    }
};

int main() {

    return 0;
}