// https://leetcode.com/problems/rotate-image/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Solution 1
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);
        
        for (int i = 0; i < n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }

    // Solution 2
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        
        int turns = 0;
        int prev = matrix[0][0];
        int r1 = 0, c1 = 0;
        while(turns != n*n) {
            int r2 = c1;
            int c2 = (n-1)-r1;
            if (visited[r2][c2]) {
                if (visited[r1][c1+1]) {
                    r1 += 1;
                    c1 = r1;
                } else {
                    c1 = c1+1;
                }
                prev = matrix[r1][c1];
                r2 = c1;
                c2 = (n-1)-r1;
            }
            int temp = matrix[r2][c2];
            matrix[r2][c2] = prev;
            prev = temp;
            visited[r2][c2] = 1;
            r1 = r2; 
            c1 = c2;
            turns++;
        }
    }
};

int main() {

    return 0;
}