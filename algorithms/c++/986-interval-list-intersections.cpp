// https://leetcode.com/problems/interval-list-intersections/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> sol;
        if (firstList.size() == 0 || secondList.size() == 0) { return sol; }
        
        int m = firstList.size();
        int n = secondList.size();
        
        int p = 0;
        int q = 0;
        
        while (p < m && q < n) {
            // Check for overlap
            if (firstList[p][1] < secondList[q][0]) {
                p++;
                continue;
            } else if (secondList[q][1] < firstList[p][0]) {
                q++;
                continue;
            }
            
            if (firstList[p][0] >= secondList[q][0]) {
                if (firstList[p][1] > secondList[q][1]) {
                    sol.push_back({ firstList[p][0], secondList[q][1] });
                    q++;
                } else if (firstList[p][1] < secondList[q][1]) {
                    sol.push_back({ firstList[p][0], firstList[p][1] });
                    p++;
                } else { 
                    sol.push_back({ firstList[p][0], firstList[p][1] });
                    p++; q++;
                }
            } else {
                if (firstList[p][1] < secondList[q][1]) {
                    sol.push_back({ secondList[q][0], firstList[p][1] });
                    p++;
                } else if (firstList[p][1] > secondList[q][1]) {
                    sol.push_back({ secondList[q][0], secondList[q][1] });
                    q++;
                } else {
                    sol.push_back({ secondList[q][0], secondList[q][1] });
                    p++; q++;
                }
            }
        }
        return sol;
    }

    // More optimal solution
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> sol;
        if (firstList.size() == 0 || secondList.size() == 0) { return sol; }
        
        int m = firstList.size();
        int n = secondList.size();
        
        int p = 0, q = 0;
        while(p < m && q < n) {
            int low = max(firstList[p][0], secondList[q][0]);
            int high = min(firstList[p][1], secondList[q][1]);
            if (low <= high) {
                sol.push_back({low, high});
            }
            
            if (firstList[p][1] < secondList[q][1])
                p++;
            else if (secondList[q][1] < firstList[p][1])
                q++;
            else {
                p++; q++;
            }
        }
        return sol;
    }
};

int main() {

    return 0;
}