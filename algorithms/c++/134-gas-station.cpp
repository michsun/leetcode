// https://leetcode.com/problems/gas-station/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canComplete(vector<int>& gas, vector<int>& cost, int n, int pos) {
        if (n == 1) return true;
        int currGas = gas[pos];
        int prevPos = pos;
        while(n--) {
            if (currGas <= 0) return false;
            pos++;
            if (pos == gas.size()) pos = 0;
            currGas -= cost[prevPos];
            if (currGas < 0) return false;
            currGas += gas[pos];
            prevPos = pos;
        }
        return currGas-cost[prevPos] > 0;
    }
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            if (gas[i] < cost[i])
                continue;
            if (canComplete(gas, cost, n, i)) 
                return i;
        }
        return -1;
    }
};

int main() {

    return 0;
}