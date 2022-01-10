// https://leetcode.com/problems/single-number/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Hashset solution
    int singleNumber(vector<int>& nums) {
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); i++) {
            auto it = set.find(nums[i]);
            if (it == set.end()) {
                set.insert(nums[i]);
            } else {
                set.erase(it);
            }
        }
        return *(set.begin());
    }

    // Bit manipulation solution
    int singleNumber(vector<int>& nums) {
        int sol = 0;
        for (int i = 0; i < nums.size(); i++)
            sol ^= nums[i];
        return sol;
    }
};

int main() {

    return 0;
}