// https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long count = prices.size();
        int curr_period = 0;
        int prev = -1;
        for (int i = 0; i < prices.size(); i++) {
            if (prev - prices[i] == 1) {
                curr_period++;
                count += curr_period;
            } else {
                curr_period = 0;
            }
            prev = prices[i];
        }
        return count;
    }
};

int main() {

    return 0;
}