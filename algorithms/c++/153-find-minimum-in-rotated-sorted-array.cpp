// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int rot = nums[0];
        int l = 0, r = nums.size()-1;
        while(l <= r) {
            int mid = (l+r)/2;
            if (nums[mid] >= rot) 
                l = mid+1;
            else { 
                if (mid > 0 && nums[mid] < nums[mid-1])
                    return nums[mid];
                r = mid-1;
            }
        }
        return rot;
    }
};

int main() {

    return 0;
}