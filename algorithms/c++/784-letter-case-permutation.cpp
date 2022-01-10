// https://leetcode.com/problems/letter-case-permutation/
#include <bits/stdc++.h>

using namespace std;

// Recursive backtracking solution - DFS
class Solution {
public:
    void backtrack(vector<string>& sol, string& s, int& n, string permutation, int pos) {
        if (permutation.size() == n) {
            sol.push_back(permutation);
            return;
        }
        char c = s[pos];
        permutation.push_back(c);
        backtrack(sol, s, n, permutation, pos+1);
        if (c >= 97) { // is lower case
            permutation.pop_back();
            permutation.push_back(char(c-32));
            backtrack(sol, s, n, permutation, pos+1);
        } else if (c >= 65) { // is upper case
            permutation.pop_back();
            permutation.push_back(char(c+32)); // lower case
            backtrack(sol, s, n, permutation, pos+1);
        } // else is digit
        
        return;
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> sol;
        int n = s.size();
        string permutation = "";
        
        backtrack(sol, s, n, permutation, 0);
        return sol;
    }
};

int main() {

    return 0;
}