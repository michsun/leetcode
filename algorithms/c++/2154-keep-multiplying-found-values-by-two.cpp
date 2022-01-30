// https://leetcode.com/problems/keep-multiplying-found-values-by-two/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int largest = nums[n-1];
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == original)
                original = original * 2;
        }
        return original;
    }
};

int main() {

    return 0;
}