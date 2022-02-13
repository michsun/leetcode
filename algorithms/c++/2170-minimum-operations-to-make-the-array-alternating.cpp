// https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        
        int n = nums.size();
        unordered_map<int,int> h1, h2;
        h1[-1] = 0;
        h2[-1] = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                h1[nums[i]]++;
            else
                h2[nums[i]]++;
        }
        
        vector<pair<int,int>> h1v, h2v;
        for (auto &item: h1) 
            h1v.emplace_back(item);
        for (auto &item: h2) {
            h2v.emplace_back(item);
            
        sort(h1v.begin(), h1v.end(), [] (const auto &x, const auto &y) {
            return x.second > y.second;
        });
        sort(h2v.begin(), h2v.end(), [] (const auto &x, const auto &y) {
            return x.second > y.second;
        });
        
        int oddn = n/2;
        int even = n/2;
        if (n % 2 == 1) oddn += 1;
        
        int count = 0;
        int p = 0, q = 0;
        while(h1v[p].first == h2v[q].first) {
            if (h1v[p].second > h2v[q].second)
                q++;
            else
                p++;
        }
        count = (oddn - h1v[p].second) + (even - h2v[q].second);
        return count;
    }
};

int main() {

    return 0;
}