// https://leetcode.com/problems/detect-capital/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if (n == 1) return true;
        if (word[1] >= 'a') {
            for (int i = 2; i < n; i++)
                if (word[i] < 'a')
                    return false;
            return true;
        } else if (word[0] <= 'Z' && word[1] <= 'Z') {
            for (int i = 2; i < n; i++)
                if (word[i] > 'Z')
                    return false;
            return true;
        }
        return false;
    }
};

int main() {

    return 0;
}