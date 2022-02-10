// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_map<char, string> letters = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
public:
    void dfs(vector<string>& sol, string& curr, string& digits, int& n, int i) {
        if (i == n) {
            sol.push_back(curr);
            return;
        }
        for (int k = 0; k < letters[digits[i]].size(); k++) {
            curr.push_back(letters[digits[i]][k]);
            dfs(sol, curr, digits, n, i+1);
            curr.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> sol;
        if (n == 0) return sol;
        string curr = "";
        dfs(sol, curr, digits, n, 0);
        return sol;
    }
};

int main() {

    return 0;
}