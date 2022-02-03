// https://leetcode.com/problems/rearrange-array-elements-by-sign/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        queue<int> pos, neg;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                pos.push(nums[i]);
            if (nums[i] < 0)
                neg.push(nums[i]);
        }
        
        vector<int> sol;
        int num;
        bool currPos = true;
        while(n--) {
            if (currPos) {
                num = pos.front();
                pos.pop();
                sol.push_back(num);
                currPos = false;
            } else {
                num = neg.front();
                neg.pop();
                sol.push_back(num);
                currPos = true;
            }
        }
        return sol;
    }
};

int main() {

    return 0;
}