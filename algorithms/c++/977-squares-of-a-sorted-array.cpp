// https://leetcode.com/problems/squares-of-a-sorted-array/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> sol(n);
        int p = 0, q = n-1;
        int pos = n-1;
        while(pos >= 0) {
            if (abs(nums[p]) <= abs(nums[q])) {
                sol[pos] = nums[q] * nums[q];
                q--;
            } else {
                sol[pos] = nums[p] * nums[p];
                p++;
            }
            pos--;
        }
        return sol;
    }
};

int main() {

    return 0;
}