// https://leetcode.com/problems/stone-game-iv/
#include <bits/stdc++.h>

using namespace std;

// DFS Solution
class Solution {
public:
    bool dfs(unordered_map<int, bool>& cache, int n) {
        if (cache.find(n) != cache.end())
            return cache[n];
        
        int root = sqrt(n);
        for (int i = 1; i <= root; i++) {
            // Check if the next player has a chance to win
            if (!dfs(cache, n - i*i)) {
                cache[n] = true;
                return true;
            }
        }
        cache[n] = false;
        return false;
    }
    
    bool winnerSquareGame(int n) {
        unordered_map<int, bool> cache;
        cache[0] = false;
        cache[1] = true;
        return dfs(cache, n);
    }
};

int main() {

    return 0;
}