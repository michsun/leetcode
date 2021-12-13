// https://leetcode.com/problems/reshape-the-matrix/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    pair<int,int> getPosition(int& col, int& target) {
        int firstVal = target / col;
        int secondVal = target % col;
        return make_pair(firstVal, secondVal);
    }
    
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> reshaped(r, vector<int>(c));
        if (mat.size() == 0 || mat[0].size() == 0) return reshaped;
        
        int n = mat.size();
        int m = mat[0].size();
        
        if (n*m != r*c) return mat;
        
        for (int k = 0; k < r*c; k++) {
            pair<int, int> matPos = getPosition(m,k);
            pair<int, int> newPos = getPosition(c,k);
            
            reshaped[newPos.first][newPos.second] = mat[matPos.first][matPos.second];
        }
        
        return reshaped;
    }
};

int main() {

    return 0;
}