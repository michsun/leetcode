// https://leetcode.com/problems/sort-colors/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int rw = 0, wb = 0; // partition between red-white and white-blue
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                nums[i] = nums[rw];
                nums[rw] = 0;
                rw++; 
                if (nums[i] == 1 && wb >= rw) {
                    nums[i] = 2;
                    nums[wb] = 1;
                }
                wb++;
            } else if (nums[i] == 1) {
                nums[i] = nums[wb];
                nums[wb] = 1;
                wb++;
            }
        }
    }
};

int main() {

    return 0;
}