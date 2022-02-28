// https://leetcode.com/problems/summary-ranges/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> sol;
        if (nums.size() == 0) return sol;
        if (nums.size() == 1) return { to_string(nums[0]) };
        
        string s = "";
        int start = nums[0], prev = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if ((long long)nums[i] - (long long)prev == 1) {
                prev = nums[i];
                continue;
            }
            if (start == prev) {
                sol.push_back(to_string(start));
            } else {
                s = to_string(start) + "->" + to_string(prev);
                sol.push_back(s);
            }
            start = nums[i];
            prev = nums[i];
        }
        
        if (start == prev) {
            sol.push_back(to_string(start));
        } else {
            s = to_string(start) + "->" + to_string(prev);
            sol.push_back(s);
        }
        
        return sol;
    }
};

int main() {

    return 0;
}