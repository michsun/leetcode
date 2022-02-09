// https://leetcode.com/problems/find-the-difference/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> hash(26,0);
        for (auto c: s)
            hash[c-'a']++;
        
        for (auto c: t) {
            hash[c-'a']--;
            if (hash[c-'a'] == -1)
                return c;
        }
        return '-';
    }
};

int main() {

    return 0;
}