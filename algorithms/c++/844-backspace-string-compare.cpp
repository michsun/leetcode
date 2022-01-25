// https://leetcode.com/problems/backspace-string-compare/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // First non-backspaced position
    void nonBackspacedPos(string& s, int& p) {
        int skip = 0;
        while(p >= 0 && (skip > 0 || s[p] == '#')) {
            if (s[p] == '#')
                skip++;
            else 
                skip--;
            p--;
        }
    }
    
    // Solution with pointers
    bool backspaceCompare(string s, string t) {
        if (s == t) return true;
        int p = s.size()-1;
        int q = t.size()-1;
        while(p >= 0 || q >= 0) {
            nonBackspacedPos(s, p); 
            nonBackspacedPos(t, q); 
            if (p < 0 || q < 0) {
                if (p < 0 && q < 0) {
                    return true;
                }
                return false;
            }
            if (s[p] != t[q]) {
                return false;
            }
            p--; q--;
        }
        return true;
    }
};

class Solution {
public:
    // Solution with stack
    bool backspaceCompare(string s, string t) {
        if (s == t) return true;
        stack<char> a, b;
        for (auto c: s) {
            if (c == '#') {
                if (!a.empty())
                    a.pop();
            } else {
                a.push(c);
            }
        }
        for (auto c: t) {
            if (c == '#') {
                if (!b.empty())
                    b.pop();
            } else {
                b.push(c);
            }
        }
        while(!a.empty() && !b.empty()) {
            if (a.top() != b.top())
                return false;
            a.pop(); b.pop();
        }
        if (a.empty() && b.empty())
            return true;
        return false;
    }
};

int main() {

    return 0;
}