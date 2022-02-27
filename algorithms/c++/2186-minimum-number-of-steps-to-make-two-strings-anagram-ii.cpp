// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> arr1(26,0), arr2(26,0);
        for (auto& c: s)
            arr1[c-'a']++;
        for (auto& c: t)
            arr2[c-'a']++;
        
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (arr1[i] != arr2[i])
                count += abs(arr1[i]-arr2[i]);
        }
        return count;
    }
};

int main() {

    return 0;
}