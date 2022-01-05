// https://leetcode.com/problems/palindrome-partitioning/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string& s, int start, int end) {
        while(start <= end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }        
        return true;
    }
    
    void partitionSearch(string& s, int start, vector<string>& pars, vector<vector<string>>& sol) {
        if (start == s.size()) {
            sol.push_back(pars);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                pars.push_back(s.substr(start, i - start + 1));
                partitionSearch(s, i+1, pars, sol);
                pars.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> pars;
        partitionSearch(s, 0, pars, ans);
        return ans;
    }
};

int main() {

    return 0;
}