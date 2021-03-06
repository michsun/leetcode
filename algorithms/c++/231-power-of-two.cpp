// https://leetcode.com/problems/power-of-two/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Loop solution
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        while(n != 2) {
            if (n % 2 == 1) return false;
            n = n/2;
        }
        return true;
    }
};

int main() {

    return 0;
}