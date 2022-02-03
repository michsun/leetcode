// https://leetcode.com/problems/largest-rectangle-in-histogram/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<pair<int,int>> stk;
        stk.push(make_pair(0, heights[0]));
        
        for (int i = 1; i < heights.size(); i++) {
            int curr_index = i;
            while (!stk.empty() && stk.top().second > heights[i]) {
                maxArea = max(maxArea, stk.top().second * (i - stk.top().first));
                curr_index = stk.top().first;
                stk.pop();
            }
            if (stk.empty())
                curr_index = 0;
            stk.push(make_pair(curr_index, heights[i]));
        }
        
        while(!stk.empty()) {
            maxArea = max(maxArea, stk.top().second * (n - stk.top().first));
            stk.pop();
        }
        
        return maxArea;
    }
};

int main() {

    return 0;
}