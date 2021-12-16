// https://leetcode.com/problems/ransom-note/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (magazine.size() < ransomNote.size()) return false;
        
        unordered_map<char, int> mp;
        for (const auto c: ransomNote) {
            if (mp.find(c) != mp.end()) {
                mp[c]++;
            } else {
                mp[c] = 1;
            }
        }
        
        for (const auto c: magazine) {
            if (mp.find(c) != mp.end()) {
                mp[c]--;
                if (mp[c] == 0) {
                    mp.erase(c);
                }
                if (mp.empty()) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {

    return 0;
}