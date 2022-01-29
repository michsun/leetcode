// https://leetcode.com/problems/all-paths-from-source-to-target/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& graph, int& n, vector<int>& path, vector<vector<int>>& sol, int i) {
        if (i == n-1) {
            sol.push_back(path);
            return;
        }
        for (int j = 0; j < graph[i].size(); j++) {
            path.push_back(graph[i][j]);
            dfs(graph, n, path, sol, graph[i][j]);
            path.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> sol;
        
        vector<int> path = {0};
        dfs(graph, n, path, sol, 0);
        
        return sol;
    }
};

int main() {

    return 0;
}