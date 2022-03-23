// https://leetcode.com/problems/broken-calculator/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int count = 0;
        while(startValue < target) {
            if (target % 2 == 1)
                target++;
            else
                target /= 2;
            count++;
        }
        return count + startValue - target;
    }
};

int main() {

    return 0;
}