// https://leetcode.com/problems/two-sum/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end()) {
                return vector<int> {mp[complement], i};
            } 
            mp[nums[i]] = i;
        }
        return vector<int>{};
    }
};

int main() {

    return 0;
}