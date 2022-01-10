// https://leetcode.com/problems/01-matrix/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // DP / two-pass solution
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat[0].size();
        int m = mat.size();
        
        int zr = m, zc = n; // smallest row/col where first zero identified
        // First pass checks top and left values - only valid once a 0 has been found
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != 0) {
                    if (i >= zr && j >= zc) {
                        if (i > 0 && j > 0)
                            mat[i][j] = 1 + min(mat[i-1][j], mat[i][j-1]);
                        else if (i > 0 && j == 0) 
                            mat[i][j] = 1 + mat[i-1][j];
                        else if (j > 0 && i == 0)
                            mat[i][j] = 1 + mat[i][j-1];
                    } else { 
                        mat[i][j] = INT_MAX; // if a zero has not yet been found, set to INT_MAX
                    }

                } else {
                    zr = min(i, zr); 
                    zc = min(j, zc);
                }
            }
        }
        
        // Second pass checks bottom and right values
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (mat[i][j] != 0) {
                    if (i < m-1 && j < n-1) 
                        mat[i][j] = min(mat[i][j], 1 + min(mat[i+1][j], mat[i][j+1]));
                    else if (i < m-1 && j == n-1)
                        mat[i][j] = min(mat[i][j], 1 + mat[i+1][j]);
                    else if (j < n-1 && i == m-1)
                        mat[i][j] = min(mat[i][j], 1 + mat[i][j+1]);
                }
            }
        }
        
        return mat;
    }
};

int main() {

    return 0;
}