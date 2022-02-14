// https://leetcode.com/problems/jump-game/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        int minJump = 1;
        for (int i = n-2; i > 0; i--) {
            if (nums[i] >= minJump)
                minJump = 1;
            else
                minJump++;
        }
        return nums[0] >= minJump;
    }
};

int main() {

    return 0;
}