// https://leetcode.com/problems/reverse-bits/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            res = (n>>i)&1 | res<<1;
        }
        return res;
    }
};

int main() {

    return 0;
}