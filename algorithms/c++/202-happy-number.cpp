// https://leetcode.com/problems/happy-number/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(seen.find(n) == seen.end() && n != 1) {
            seen.insert(n);
            string s = to_string(n);
            n = 0;
            for (auto c: s)
                n += (c-'0')*(c-'0');
        }
        if (n == 1) 
            return true;
        return false;
    }
};

int main() {

    return 0;
}