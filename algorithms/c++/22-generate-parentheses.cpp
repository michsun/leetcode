// https://leetcode.com/problems/generate-parentheses/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	// Generates string based on number of valid left/right brackets
    void generate(vector<string>& sol, string& curr, int left, int right) {
        if (left == 0 && right == 0) {
            sol.push_back(curr);
            return;
        }
        if (left > 0) {
            curr.push_back('(');
            generate(sol, curr, left-1, right+1); // removing a left bracket adds a valid right bracket
            curr.pop_back();
        }
        if (right > 0) {
            curr.push_back(')');
            generate(sol, curr, left, right-1); // reduces number of valid right brackets
            curr.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> sol;
        string curr = "";
		// Start with n valid left brackets and 0 valid right brackets
        generate(sol, curr, n, 0);
        return sol;
    }
};

int main() {

    return 0;
}