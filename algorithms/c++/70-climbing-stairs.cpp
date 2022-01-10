// https://leetcode.com/problems/climbing-stairs/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        while (--n) {
            b += a;
            a = b-a;
        }
        return b;
    }
};

int main() {

    return 0;
}