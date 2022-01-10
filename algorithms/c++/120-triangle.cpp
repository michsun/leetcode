// https://leetcode.com/problems/triangle/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 1) return triangle[0][0];
        int minPath = INT_MAX;
        int m = 1; // size of prev row in triangle
        for (int i = 1; i < triangle.size(); i++) {
            minPath = INT_MAX;
            for (int j = 0; j <= m; j++) {
                if (j == 0) 
                    triangle[i][j] += triangle[i-1][j];
                else if (j == m)
                    triangle[i][j] += triangle[i-1][j-1];
                else
                    triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
                minPath = min(minPath, triangle[i][j]);
            }
            m++;
        }
        return minPath;
    }
};

int main() {

    return 0;
}