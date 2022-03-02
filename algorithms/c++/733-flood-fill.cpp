// https://leetcode.com/problems/flood-fill/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        int prevColor = image[sr][sc];
        
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int,int>> q;
        q.push(make_pair(sr,sc));
        
        while(!q.empty()) {
            pair<int,int> pos = q.front();
            q.pop();
            int& row = pos.first;
            int& col = pos.second;
            image[row][col] = newColor;
            visited[row][col] = 1;        

            if (row > 0 && !visited[(--row)++][col] && image[(--row)++][col] == prevColor)
                q.push(make_pair((--row)++, col));
            if (row < n-1 && !visited[(++row)--][col] && image[(++row)--][col] == prevColor)
                q.push(make_pair((++row)--, col));
            if (col > 0 && !visited[row][(--col)++] && image[row][(--col)++] == prevColor)
                q.push(make_pair(row, (--col)++));
            if (col < m-1 && !visited[row][(++col)--] && image[row][(++col)--] == prevColor)
                q.push(make_pair(row, (++col)--));
        }
        return image;
    }
};

class Solution2 {
public:
    void dfs(vector<vector<int>>& image, int& m, int& n, int& prevColor, int& newColor, int row, int col) {
        cout << row << ' ' << col << '\n';
        image[row][col] = newColor;
        if (row > 0 && image[row-1][col] == prevColor)
            dfs(image, m, n, prevColor, newColor, row-1, col);
        if (row < m-1 && image[row+1][col] == prevColor)
            dfs(image, m, n, prevColor, newColor, row+1, col);
        if (col > 0 && image[row][col-1] == prevColor)
            dfs(image, m, n, prevColor, newColor, row, col-1);
        if (col < n-1 && image[row][col+1] == prevColor)
            dfs(image, m, n, prevColor, newColor, row, col+1);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        int prevColor = image[sr][sc];
        if (prevColor != newColor)
            dfs(image, m, n, prevColor, newColor, sr, sc);
        return image;
    }
};

int main() {

    return 0;
}