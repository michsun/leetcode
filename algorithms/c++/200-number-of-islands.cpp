// https://leetcode.com/problems/number-of-islands/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int& m, int& n, int i, int j, vector<vector<int>>& visited) {
        if (visited[i][j] || grid[i][j] == '0')
            return;
        visited[i][j] = 1;
        if (i > 0) { dfs(grid, m, n, i-1, j, visited); }
        if (j > 0) { dfs(grid, m, n, i, j-1, visited); }
        if (i < m-1) { dfs(grid, m, n, i+1, j, visited); }
        if (j < n-1) { dfs(grid, m, n, i, j+1, visited); }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n));
        int count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j])
                    continue;
                if (grid[i][j] == '1') {
                    dfs(grid, m, n, i, j, visited);
                    count++;
                }
            }
        }
        
        return count;
    }
};

int main() {

    return 0;
}