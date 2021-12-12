// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        
        int lowest_so_far = prices[0];
        int highest_so_far = 0;
        int highest_profit = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < lowest_so_far) {
                lowest_so_far = prices[i];
                highest_so_far = 0;
            } else if (prices[i] > lowest_so_far) {
                highest_so_far = max(highest_so_far, prices[i]);
            }
            int curr_profit = highest_so_far - lowest_so_far;
            highest_profit = max(highest_profit, curr_profit);
        }
        return highest_profit;
    }
};

int main() {

    return 0;
}