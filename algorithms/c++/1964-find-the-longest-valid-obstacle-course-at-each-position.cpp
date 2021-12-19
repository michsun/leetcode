// https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Greedy and Binary Search O(nlogn)
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans(obstacles.size(), 1);
        vector<int> sub = { obstacles[0] };
        
        for (int i = 1; i < obstacles.size(); i++) {
            if ( sub[sub.size()-1] <= obstacles[i] ) {
                sub.push_back(obstacles[i]);
                ans[i] = sub.size();
            } else {
                int index = upper_bound(sub.begin(), sub.end(), obstacles[i]) - sub.begin(); // Index of the smallest number > obstacles[i]
                sub[index] = obstacles[i];
                ans[i] = index+1;
            }
        }
        return ans;
    }
    
    // Dynamic Programming - TLE
//     vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
//         if (obstacles.size() == 1) return {1};
//         vector<int> dp(obstacles.size(), 1);
        
//         for (int j = 1; j < obstacles.size(); j++) {
//             for (int i = 0; i < j; i++) {
//                 if (obstacles[j] >= obstacles[i]) {
//                     if (dp[i]+1 > dp[j]) {
//                         dp[j] = dp[i]+1;
//                     }
//                 }
//             }
//         }
//         return dp;
//     }
};

int main() {

    return 0;
}