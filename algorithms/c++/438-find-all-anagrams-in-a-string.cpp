// https://leetcode.com/problems/find-all-anagrams-in-a-string/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {};
        
        int m = s.size();
        int n = p.size();
        
        vector<int> hash(26), curr(26);
        for (auto c: p)
            hash[c-'a'] += 1;
        
        for (int i = 0; i < n; i++)
            curr[s[i]-'a'] += 1;
        
        vector<int> sol;
        if (hash == curr)
            sol.push_back(0);
        
        for (int i = n; i < m; i++) {
            curr[s[i-n]-'a'] -= 1;
            curr[s[i]-'a'] += 1;
            if (hash == curr)
                sol.push_back(i-n+1);
        }
        return sol;
    }
};

int main() {

    return 0;
}