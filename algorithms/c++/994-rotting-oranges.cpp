// https://leetcode.com/problems/rotting-oranges/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<queue<pair<int,int>>> q;
        queue<pair<int,int>> initial;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    initial.push(make_pair(i,j));
                }
            }
        }
        if (!initial.empty()) q.push(initial);
        
        int count = 0;
        while(!q.empty()) {
            queue<pair<int,int>> search = q.front();
            q.pop();
            queue<pair<int,int>> newRotten = {};
            int rottenSpread = 0;
            
            while(!search.empty()) {
                int i = search.front().first;
                int j = search.front().second;
                search.pop();
                vector<vector<int>> positions = {{i-1, j}, {i+1, j}, {i, j-1}, {i, j+1}};
                for (auto& pos: positions) {
                    int& a = pos[0], b = pos[1];
                    if (a >= 0 && b >= 0 && a < m && b < n) {
                        if (grid[a][b] == 1) {
                            grid[a][b] = 2;
                            rottenSpread = 1;
                            newRotten.push(make_pair(a,b));
                        }
                    }
                }
            }
            if (rottenSpread)
                count++;
            if (!newRotten.empty())
                q.push(newRotten);
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return count;
    }
};

int main() {

    return 0;
}