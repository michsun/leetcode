// https://leetcode.com/problems/arithmetic-slices/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        int n = nums.size();
        
        int count = 0;
        int l = 0;
        while(l < n-1) {
            int diff = nums[l+1] - nums[l];
            if (nums[l+2] - nums[l+1] != diff) {
                l++;
                continue;
            }
            
            int r = l+3;
            while(r < n && nums[r] - nums[r-1] == diff) {
                r++;
            }
            int len = r-l;
            int slices = 1;
            while(len >= 3) {
                count += slices++;
                len--;
            }
            l = r-1;
        }
        return count;
    }
};

int main() {

    return 0;
}