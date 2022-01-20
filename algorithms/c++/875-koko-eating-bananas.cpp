// https://leetcode.com/problems/koko-eating-bananas/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Binary Search solution
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1000000000;
        int midSpeed = 0, hours = 0;
        while(l < r) {
            midSpeed = (l+r)/2, hours = 0;
            for (auto p : piles)
                hours += (p % midSpeed == 0) ? p/midSpeed : p/midSpeed + 1;
            if (hours > h)
                l = midSpeed +1;
            else
                r = midSpeed;
        }
        return l;
    }
};

int main() {

    return 0;
}