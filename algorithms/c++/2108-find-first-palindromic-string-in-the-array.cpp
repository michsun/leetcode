// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string& s) {
        int p = 0;
        int q = s.size()-1;
        while(p <= q) {
            if (s[p] != s[q]) return false;
            p++; q--;
        }
        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
        for (auto& word: words) {
            if (isPalindrome(word)) return word;
        }
        return "";
    }
};

int main() {

    return 0;
}