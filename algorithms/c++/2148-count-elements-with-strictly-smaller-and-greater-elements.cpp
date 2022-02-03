// https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countElements(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size()-1;
        if (nums[l] == nums[r]) return 0;
        l++; r--;
        
        while(l <= r) {
            if (nums[l] > nums[l-1] && nums[r] < nums[r+1])
                return r - l + 1;
            if (nums[l] == nums[l-1])
                l++;
            if (nums[r] == nums[r+1])
                r--;
        }
        
        return 0;
    }
};

int main() {

    return 0;
}