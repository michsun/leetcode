// https://leetcode.com/problems/increasing-triplet-subsequence/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int smallest = INT_MAX, middle = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > smallest) {
                if (nums[i] > middle) return true;
                middle = min(middle, nums[i]);
            }
            smallest = min(smallest, nums[i]);
        }
        return false;
    }
};

int main() {

    return 0;
}