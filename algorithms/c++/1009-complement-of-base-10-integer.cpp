// https://leetcode.com/problems/complement-of-base-10-integer/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        int x = 1;
        while (n > x) x = x * 2 + 1;
        return x - n;
    }
};

int main() {

    return 0;
}