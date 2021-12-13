// https://leetcode.com/problems/consecutive-characters/submissions/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int power = 0;
        int curr = 0;
        char prev = '_';
        for (auto c: s) {
            curr = c != prev ? 1 : curr + 1;
            power = max(power, curr);
            prev = c;
        }
        return power;
    }
};

int main() {

    return 0;
}