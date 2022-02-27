// https://leetcode.com/problems/counting-words-with-a-given-prefix/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        int m = pref.size();
        for (int i = 0; i < words.size(); i++) {
            if (words[i].size() < m)
                continue;
            int j = 0;
            while(j < m) {
                if (words[i][j] != pref[j])
                    break;
                j++;
            }
            if (j == m)
                count++;
        }
        return count;
    }
};

int main() {

    return 0;
}