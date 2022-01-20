// https://leetcode.com/problems/sqrtx/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int l = 1, r = x;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if (mid > x/mid && (mid-1) <= x/(mid-1))
                return mid-1;
            if (mid > x/mid)
                r = mid-1;
            else
                l = mid+1;
        }
        return r;
    }
};

int main() {

    return 0;
}