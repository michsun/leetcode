// https://leetcode.com/problems/valid-parentheses/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() <= 1) return false;
        unordered_map<char, char> dict {
            {'(',')'},
            {'{','}'},
            {'[',']'}
        };
        stack<char> stk;
        
        for (const auto c: s) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else if (!stk.empty() && dict[stk.top()] == c) {
                stk.pop();
            } else {
                return false;
            }
        }
        if (stk.empty()) return true;
        return false;
    }
};

int main() {

    return 0;
}