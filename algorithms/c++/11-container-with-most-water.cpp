// https://leetcode.com/problems/container-with-most-water/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int sol = 0;
        int l = 0, r = height.size()-1;
        while(l < r) {
            sol = max(sol, (r-l)*min(height[l], height[r]));
            if (height[l] <= height[r])
                l++;
            else
                r--;
        }
        return sol;
    }
};

int main() {

    return 0;
}