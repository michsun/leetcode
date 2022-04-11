// https://leetcode.com/problems/shift-2d-grid/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if (k == 0) return grid;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> newGrid(m, vector<int>(n));
        int total = m*n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int newPos = (i * n + j + k) % total;
                int newRow = newPos / n;
                int newCol = newPos % n;
                newGrid[newRow][newCol] = grid[i][j];
            }
        }
        return newGrid;
    }
};

int main() {

    return 0;
}