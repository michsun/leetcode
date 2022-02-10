// https://leetcode.com/problems/word-search/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, int& m, int& n, string& word, vector<vector<int>>& visited, int i, int j, int k) {
        if (board[i][j] != word[k])
            return false;
        visited[i][j] = 1;
        if (k == word.size()-1)
            return true;
        
        if (i > 0 && !visited[i-1][j]) {
            if (dfs(board, m, n, word, visited, i-1, j, k+1))
                return true;
            visited[i-1][j] = 0;
        }
        if (j > 0 && !visited[i][j-1]) {
            if (dfs(board, m, n, word, visited, i, j-1, k+1))
                return true;
            visited[i][j-1] = 0;
        }
        if (i < m-1 && !visited[i+1][j]) {
            if (dfs(board, m, n, word, visited, i+1, j, k+1))
                return true;
            visited[i+1][j] = 0;
        }
        if (j < n-1 && !visited[i][j+1]) {
            if (dfs(board, m, n, word, visited, i, j+1, k+1))
                return true;
            visited[i][j+1] = 0;
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word[0] == board[i][j]) {
                    if (dfs(board, m, n, word, visited, i, j, 0))
                        return true;
                    else
                        visited[i][j] = 0;
                }
            }
        }
        return false;
    }
};

int main() {

    return 0;
}