// https://leetcode.com/problems/valid-sudoku/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // Are rows valid
        vector<vector<int>> rowHash(9, vector<int>(9,0));
        vector<vector<int>> colHash(9, vector<int>(9,0));
        vector<vector<int>> subHash(9, vector<int>(9,0));
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] != '.') {
                    int val = board[i][j] - '0' - 1;
                    
                    // Valid in row
                    if (rowHash[i][val] == 1) return false;
                    else rowHash[i][val] = 1;
                    
                    // Valid in col
                    if (colHash[j][val] == 1) return false;
                    else colHash[j][val] = 1;
                        
                    // Valid in sub-box
                    int boxNum = (i/3*3) + j/3;
                    if (subHash[boxNum][val] == 1) return false;
                    else subHash[boxNum][val] = 1;
                }
            }
        }
        return true;
    }
};

int main() {

    return 0;
}