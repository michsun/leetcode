// https://leetcode.com/problems/maximal-square/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxVal = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = matrix[i][j] - '0';
                if (i > 0 && j > 0 && matrix[i][j] == '1') {
                    if (matrix[i][j-1] == '1' && matrix[i-1][j] == '1' && matrix[i-1][j-1] == '1') {
                        int minVal = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
                        dp[i][j] = minVal + 1;
                    }
                }
                maxVal = max(maxVal, dp[i][j]);
            }
        }
        return maxVal*maxVal;
    }
};

int main() {

    return 0;
}