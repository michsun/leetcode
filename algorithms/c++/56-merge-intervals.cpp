// https://leetcode.com/problems/merge-intervals/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) return intervals;
        // sort(intervals.begin(), intervals.end(), [](auto first, auto second) {
        //     return first[0] < second[0];
        // });
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> solution;
        vector<int> range = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > range[1]) {
                solution.push_back(range);
                range = intervals[i];
            } 
            if (intervals[i][0] <= range[1]) {
                range[1] = max(intervals[i][1], range[1]);
            }
        }
        solution.push_back(range);
        return solution;
    }
};

int main() {

    return 0;
}