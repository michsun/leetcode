#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++) {
            if (seen.find(nums[i]) != seen.end()) {
                return true;
            }
            seen[nums[i]] = 1;
        }
        return false;
    }
}