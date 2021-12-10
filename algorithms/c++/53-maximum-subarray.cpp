#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_here = 0;
        int max_so_far = -10000;
        for (auto num: nums) {
            max_here = max(num, max_here + num);
            max_so_far = max(max_here, max_so_far);
        }
        return max_so_far;
    }
};