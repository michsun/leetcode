// https://leetcode.com/problems/search-a-2d-matrix-ii/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix[0].size();
        int top = 0, bottom = matrix.size()-1;
        int col = 0;
        
        while(col < m) {
            bool maxRowFound = false;
            while(!maxRowFound) {
                if (top > bottom) {
                    maxRowFound = true;
                    continue;
                }
                int mid = (top+bottom)/2;
                if (matrix[mid][col] == target) 
                    return true;
                if (matrix[mid][col] > target)
                    bottom = mid - 1;
                else
                    top = mid + 1;
            }
            top = 0;
            col++;
        }
        return false;
    }
};

int main() {

    return 0;
}