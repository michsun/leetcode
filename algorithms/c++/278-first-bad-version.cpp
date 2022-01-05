// https://leetcode.com/problems/first-bad-version/
#include <bits/stdc++.h>

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        
        while(left <= right) {
            int mid = left + (right - left)/2; // bypass int overflow
            if (isBadVersion(mid) && (mid == 1 || !isBadVersion(mid-1)))
                return mid;
            if (isBadVersion(mid))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};

int main() {

    return 0;
}