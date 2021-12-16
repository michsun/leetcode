// https://leetcode.com/problems/first-unique-character-in-a-string/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        if (s.size() == 1) return 0;
        vector<int> vec(26,0);
        for (const auto c: s) {
            vec[c-'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (vec[s[i]-'a'] == 1) 
                return i;
        }
        return -1;
    }    
};

int main() {

    return 0;
}