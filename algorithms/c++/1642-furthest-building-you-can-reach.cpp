// https://leetcode.com/problems/furthest-building-you-can-reach/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        if (heights.size() == 1) return 0;
        
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> ladder_jumps; 
        int curr_bricks = 0;
        
        for (int i = 1; i < n; i++) {
            if (heights[i] <= heights[i-1])
                continue;
            int diff = heights[i] - heights[i-1];
            if (ladder_jumps.size() < ladders) {
                ladder_jumps.push(diff);
                continue;
            }
            if (!ladder_jumps.empty()) {
                int smallest_ladder = ladder_jumps.top();
                if (diff > smallest_ladder) {
                    curr_bricks += smallest_ladder;
                    ladder_jumps.push(diff);
                    ladder_jumps.pop();
                } else {
                    curr_bricks += diff;
                }
            } else {
                curr_bricks += diff;
            }
            
            if (curr_bricks > bricks)
                return i-1;
        }
        return n - 1;
    }
};

int main() {

    return 0;
}