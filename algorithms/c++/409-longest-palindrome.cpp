// https://leetcode.com/problems/longest-palindrome/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        set<char> hash;
        for (int i = 0; i < s.size(); i++) {
            if (hash.find(s[i]) != hash.end()) {
                hash.erase(s[i]);
                ans++;
            } else {
                hash.insert(s[i]);
            }
        }
        if (hash.empty()) return ans * 2;
        return ans * 2 + 1;
    }
};

int main() {

    return 0;
}