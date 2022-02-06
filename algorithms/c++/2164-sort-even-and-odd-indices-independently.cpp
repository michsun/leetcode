// https://leetcode.com/problems/sort-even-and-odd-indices-independently/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        if (nums.size() <= 2) return nums;
        for (int i = 2; i < nums.size(); i++) {
            int j = i;
            if (i % 2 == 1) {
                while(j > 2 && nums[j-2] < nums[j]) {
                    swap(nums[j-2], nums[j]);
                    j -= 2;
                }
            } else {
                while(j >= 2 && nums[j-2] > nums[j]) {
                    swap(nums[j-2], nums[j]);
                    j -= 2;
                }
            }
        }
        return nums;
    }
};

int main() {

    return 0;
}