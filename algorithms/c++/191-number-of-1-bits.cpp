// https://leetcode.com/problems/number-of-1-bits/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Bitwise method
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n > 0) {
            n &= n-1;
            count++;
        }
        return count;
    }

    // Non-bitwise method
    int hammingWeight(uint32_t n) {
        int count = 0;
        int m = 32;
        while(m-- && n > 0) {
            if (int(n/pow(2,m)) == 1) {
                count++;
                n -= pow(2,m);
            }
        }
        return count;
    }
};

int main() {

    return 0;
}