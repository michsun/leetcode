// https://leetcode.com/problems/contiguous-array/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sol = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) k++;
            else k--;
            if (mp.find(k) == mp.end()) 
                mp[k] = i;
            else 
                sol = max(sol, i-mp[k]);
        }
        return sol;
    }
};

int main() {

    return 0;
}