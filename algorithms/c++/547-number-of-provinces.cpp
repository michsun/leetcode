// https://leetcode.com/problems/number-of-provinces/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int& n, vector<int>& searched, int i) {
        for (int j = 0; j < n; j++) {
            if (i != j && !searched[j] && isConnected[i][j] == 1) {
                searched[j] = 1;
                dfs(isConnected, n, searched, j);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces = 0;
        
        vector<int> searched(n);
        for (int i = 0; i < n; i++) {
            if (!searched[i]) {
                searched[i] = 1;
                provinces++;
                dfs(isConnected, n, searched, i);
            }
        }
        return provinces;
    }
};

int main() {

    return 0;
}