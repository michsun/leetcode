// https://leetcode.com/problems/spiral-matrix-ii/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        
        int rowStart = 0, rowEnd = n-1;
        int colStart = 0, colEnd = n-1;
        int counter = 0;
        
        while(rowStart <= rowEnd && colStart <= colEnd) {
            for (int i = colStart; i <= colEnd; i++)
                ans[rowStart][i] = ++counter;
            rowStart++;
            
            for (int i = rowStart; i <= rowEnd; i++)
                ans[i][colEnd] = ++counter;
            colEnd--;
            
            for (int i = colEnd; i >= colStart; i--)
                ans[rowEnd][i] = ++counter;
            rowEnd--;
            
            for (int i = rowEnd; i >= rowStart; i--)
                ans[i][colStart] = ++counter;
            colStart++;
        }
        return ans;
    }
};

int main() {

    return 0;
}