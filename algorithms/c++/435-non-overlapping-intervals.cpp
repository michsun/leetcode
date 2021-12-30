// https://leetcode.com/problems/non-overlapping-intervals/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &first, vector<int> &second) {
            return first[1] < second[1];
        });
        
        int count = 0;
        int end = INT_MIN;
        for (auto &i : intervals) {
            if (i[0] < end) 
                count++;
            else 
                end = i[1];
        }
        return count;
    }
};

int main() {

    return 0;
}