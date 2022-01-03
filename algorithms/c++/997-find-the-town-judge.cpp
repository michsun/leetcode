// https://leetcode.com/problems/find-the-town-judge/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, set<int>> mp;
        for (int i = 1; i <= n; i++) mp[i];
        vector<int> exclude(n, 0);
        
        for (int i = 0; i < trust.size(); i++) {
            mp[trust[i][1]].insert(trust[i][0]);
            exclude[trust[i][0]-1] = 1;
        }
        
        for (auto & it: mp) 
            if (it.second.size() == n-1)
                if (!exclude[it.first-1])
                    return it.first;
        return -1;
    }
};

int main() {

    return 0;
}