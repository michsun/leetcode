// https://leetcode.com/problems/single-number/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
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
};

int main() {

    return 0;
}