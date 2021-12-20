// https://leetcode.com/problems/minimum-absolute-difference/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> ans;
        ans.push_back({arr[0], arr[1]});
        int minimum = arr[1]-arr[0];
        
        for (int i = 2; i < arr.size(); i++) {
            if (arr[i]-arr[i-1] < minimum) {
                ans = {;
                ans.push_back({arr[i-1], arr[i]});
                minimum = arr[i]-arr[i-1];
            } else if (arr[i]-arr[i-1] == minimum) {
                ans.push_back({arr[i-1], arr[i]});
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}