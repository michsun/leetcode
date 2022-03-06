// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;
    int countOrders(int n) {
        long long count = 1;
        long spaces = n;
        for (int i = 1; i <= n; i++) {
            count = count * spaces % MOD;
            spaces += (n - i);
        }
        return count;
    }
};

int main() {

    return 0;
}