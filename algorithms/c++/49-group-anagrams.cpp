// https://leetcode.com/problems/group-anagrams/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, int> mp; // mp storing rearranged str and their index
        int idx = 0;                                                        
        vector<vector<string>> ans;
        
        for (auto & str: strs) {
            string copy = str;
            sort(copy.begin(), copy.end());
            if (mp.find(copy) == mp.end()) {
                mp[copy] = idx++;
                ans.resize(idx);
            }
            
            int ansIdx = mp[copy];
            ans[ansIdx].push_back(str);
        }
        return ans;
    }
};

int main() {

    return 0;
}