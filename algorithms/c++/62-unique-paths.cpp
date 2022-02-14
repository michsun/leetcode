// https://leetcode.com/problems/unique-paths/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n));
        grid[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0)
                    grid[i][j] += grid[i-1][j];
                if (j > 0)
                    grid[i][j] += grid[i][j-1];
            }
        }
        return grid[m-1][n-1];
    }
};

int main() {

    return 0;
}