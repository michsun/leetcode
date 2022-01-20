// https://leetcode.com/problems/length-of-last-word/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        bool space = false;
        for (auto c: s) {
            if (c == ' ') {
                space = true;
                continue;
            }
            if (space)
                length = 1;
            else
                length++;
            space = false;
        }
        return length;
    }
};

int main() {

    return 0;
}