// https://leetcode.com/problems/remove-element/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) return 0;
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                k++;
            } else {
                nums[i-k] = nums[i];
            }
        }
        k = nums.size() - k;
        return k;
    }
};

int main() {

    return 0;
}