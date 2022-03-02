// https://leetcode.com/problems/is-subsequence/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int p = 0;
        for (int i = 0; i < t.size(); i++) {
            if (p < n && s[p] == t[i])
                p++;
        }
        return p == n;
    }
};

int main() {

    return 0;
}