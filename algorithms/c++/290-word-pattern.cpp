// https://leetcode.com/problems/word-pattern/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        set<string> words;
        int p = 0; // s pointer
        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string buffer = "";
            while(p < s.size() && s[p] != ' ') {
                buffer += s[p];
                p++;
            }
            if (buffer == "") return false;
            if (mp.find(c) != mp.end()) {
                if (mp[c] != buffer)
                    return false;
            } else {
                if (words.find(buffer) == words.end()) {
                    words.insert(buffer);
                    mp[c] = buffer;
                }
                else
                    return false;
            }
            p++; // space
        }
        if (p < s.size()) return false;
        
        return true;
    }
};

int main() {

    return 0;
}