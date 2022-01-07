// https://leetcode.com/problems/max-area-of-island/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int islandArea(vector<vector<int>>& grid, int& n, int& m, int r, int c, vector<vector<int>>& visited) {
        if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 0 || visited[r][c] == 1)
            return 0;
        visited[r][c] = 1;
        int area = 1;
        
        area += islandArea(grid, n, m, r-1, c, visited);
        area += islandArea(grid, n, m, r+1, c, visited);
        area += islandArea(grid, n, m, r, c-1, visited);
        area += islandArea(grid, n, m, r, c+1, visited);
        
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int maxArea = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    maxArea = max(maxArea, islandArea(grid, n, m, i, j, visited));
                }
            }
        }
        
        return maxArea;
    }
};

int main() {

    return 0;
}