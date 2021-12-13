// https://leetcode.com/problems/pascals-triangle/submissions/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows);
        pascal[0].push_back(1);
        
        for (int i = 1; i < numRows; i++) {
            pascal[i].resize(i+1, 1);
            for (int j = 1; j < i; j++) {
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
        return pascal;
    }
};

int main() {

    return 0;
}