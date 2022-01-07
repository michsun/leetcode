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

int main() {

    return 0;
}