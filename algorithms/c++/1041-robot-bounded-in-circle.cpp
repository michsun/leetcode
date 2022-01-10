// https://leetcode.com/problems/robot-bounded-in-circle/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0;
        int y = 0;
        int d = 0; 
        vector<vector<int>> dirs = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (auto &c : instructions) {
            if (c == 'G') {
                x += dirs[d][0];
                y += dirs[d][1];
            }
            if (c == 'L') {
                d = d-1 == -1 ? 3 : d-1;
            }
            if (c == 'R') {
                d = d+1 == 4 ? 0 : d+1;
            }
        }
        if (x == 0 && y == 0) return true;
        if (d > 0) return true;
        return false;
    }
};

int main() {

    return 0;
}