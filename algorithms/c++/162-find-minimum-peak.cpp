// https://leetcode.com/problems/find-peak-element/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l <= r) {
            int mid = (l+r)/2;
            bool hasBefore = mid > 0;
            bool hasAfter = mid < n-1;
            if (hasBefore && hasAfter) {
                if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                    return mid;
            }
            if (hasBefore && nums[mid] < nums[mid-1])
                r = mid-1;
            else
                l = mid+1;
        }
        return r;
    }
};   

int main() {

    return 0;
}