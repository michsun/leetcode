// https://leetcode.com/problems/permutation-in-string/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        vector<int> target(26), curr(26);
        for (auto c: s1)
            target[c-'a'] += 1;
        
        for (int i = 0; i < s2.size(); i++) {
            curr[s2[i]-'a'] += 1;
            if (i >= m)
                curr[s2[i-m] - 'a'] -= 1;
            if (curr == target)
                return true;
        }
        return false;
    }
};

int main() {

    return 0;
}