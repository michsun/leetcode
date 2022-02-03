// https://leetcode.com/problems/richest-customer-wealth/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        for (int i = 0; i < accounts.size(); i++) {
            int currWealth = 0;
            for (int j = 0; j < accounts[i].size(); j++) {
                currWealth += accounts[i][j];
            }
            maxWealth = max(maxWealth, currWealth);
        }
        return maxWealth;
    }
};

int main() {

    return 0;
}