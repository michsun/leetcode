// https://leetcode.com/problems/k-diff-pairs-in-an-array/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (nums.size() <= 1) return 0;
        int n = nums.size();
        int count = 0;
        sort(nums.begin(), nums.end());
        int p = 0, q = 1, diff;
        while(q < n) {
            diff = nums[q] - nums[p];
            if (diff == k) {
                count++;
                while(q < n-1 && nums[q] == nums[q+1]) { q++; }
                while(p < n-2 && nums[p] == nums[p+1]) { p++; }
                q++; p++;
            } else if (diff < k) {
                q++;
            } else {
                p++;
            }
            if (p == q) q++;
        }
        return count;
    }
};

int main() {

    return 0;
}