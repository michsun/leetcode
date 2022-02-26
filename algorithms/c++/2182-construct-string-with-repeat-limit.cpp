// https://leetcode.com/problems/construct-string-with-repeat-limit/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> letters(26,0);
        for (auto& c: s)
            letters[c-'a']++;
        
        string newString = "";
        int i = 25;
        int prev = -1;
        while(i >= 0) {
            if (letters[i] == 0) {
                i--;
                continue;
            }
            int count = 0;
            while(letters[i] > 0 && count < repeatLimit) {
                char c = i+'a';
                newString.push_back(c);
                letters[i]--;
                count++;
                if (prev != -1 && prev != i)
                    break;
            }
            // cout << newString << ' ' << prev << '\n';
            if (letters[i] > 0 && prev == -1) {
                prev = i;
                i--;
                continue;
            }
            if (letters[i] > 0 && prev == i) {
                i--;
                continue;
            }
            if (letters[i] == 0 && prev == i) {
                prev = -1;
                i--;
            }
            if (prev != -1 && prev != i) {
                i = prev;
            }
        }
        return newString;
    }
};

int main() {

    return 0;
}