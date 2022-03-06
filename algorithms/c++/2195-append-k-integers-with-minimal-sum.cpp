// https://leetcode.com/problems/append-k-integers-with-minimal-sum/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        long long sum = 0;        
        int i = 0;
        int start = 1;
        while(k > 0) {
            if (i < n) {
                if (nums[i] > start) {
                    int diff = (nums[i] - start) > k ? k : nums[i] - start;
                    sum += ((long long)diff * (long long)(start + start + diff - 1)) / 2;
                    k -= diff;
                } 
                start = nums[i] + 1;
                i++;
            } else {
                sum += ((long long)k * (long long)(start + start + k - 1))/2;
                k = 0;
            }
        }
        return sum;
    }
};

int main() {

    return 0;
}