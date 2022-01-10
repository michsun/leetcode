// https://leetcode.com/problems/combinations/
#include <bits/stdc++.h>

using namespace std;

// Recursive solution
class Solution {
public:
    void backtrack(vector<vector<int>>& sol, int start, int& n, int& k, vector<int> comb) {
        if (comb.size() == k) {
            sol.push_back(comb);
            return;
        }
        for (int i = start; i <= n; i++) {
            comb.push_back(i);
            backtrack(sol, i+1, n, k, comb);
            comb.pop_back();
        }
        return;
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> sol ;
        vector<int> comb;
        backtrack(sol, 1, n, k, comb);
        return sol;
    }
};

int main() {

    return 0;
}