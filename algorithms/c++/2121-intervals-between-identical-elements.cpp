// https://leetcode.com/problems/intervals-between-identical-elements/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        // Initialise hashmap
        unordered_map<int,vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        
        vector<long long> ans(n,0);
        // Iterate through hashmap
        for (auto &it: mp) {
            vector<int> &v = it.second;
            int k = v.size();
            if (k > 1) { // Ignore elements that occur once
                
                // Calculate sum of all indices
                long long indexSum = 0; 
                for (auto& idx: v) 
                    indexSum += idx;
                ans[v[0]] = indexSum - (k* v[0]); // Solution for first index
                
                // Calculate current interval sum using previous solution and 
                // delta -> difference between current index and prev index
                for (int i = 1; i < k; i++) {
                    int delta = v[i] - v[i-1]; 
                    ans[v[i]] = ans[v[i-1]] + i * delta - (k-i) * delta;
                }
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}