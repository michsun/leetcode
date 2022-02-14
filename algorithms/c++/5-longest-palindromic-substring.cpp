// https://leetcode.com/problems/longest-palindromic-substring/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 1) return s;
        string res = "";
        int maxLen = 0;
        
        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]) {
                if (r-l+1 > maxLen) {
                    maxLen = r-l+1;
                    res = s.substr(l, maxLen);
                }
                l--; r++;
            }
            
            l = i; r = i+1;
            while(l >= 0 && r < n && s[l] == s[r]) {
                if (r-l+1 > maxLen) {
                    maxLen = r-l+1;
                    res = s.substr(l, maxLen);
                }
                l--; r++;
            }
        }
        return res;
    }
};

int main() {

    return 0;
}