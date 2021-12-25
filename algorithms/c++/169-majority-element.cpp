// https://leetcode.com/problems/majority-element/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxCount = 1;
        int maxElement = nums[0];
        mp[maxElement] = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end()) {
                if (++mp[nums[i]] > maxCount) {
                    maxElement = nums[i];
                    maxCount = mp[nums[i]];
                }
            } else {
                mp[nums[i]] = 1;
            }
        }
        return maxElement;
    }
};

int main() {

    return 0;
}