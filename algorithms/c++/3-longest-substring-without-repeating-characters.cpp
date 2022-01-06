// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int longest = 1;
        int prev = 1;
        unordered_map<char, int> mp; // character and last seen position
        mp[s[0]] = 0;
        
        for (int i = 1; i < s.size(); i++) {
            if (mp.find(s[i]) == mp.end()) {
                prev++;
            } else {
                if (i - mp[s[i]] > prev)
                    prev++;
                else
                    prev = i - mp[s[i]];
            }
            mp[s[i]] = i;
            longest = max(longest, prev);
        }
        return longest;
    }
};

int main() {

    return 0;
}