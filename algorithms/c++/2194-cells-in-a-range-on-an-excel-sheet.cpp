// https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> sol;
        char col = s[0];
        char row = s[1];
        while(col <= s[3]) {
            while(row <= s[4]) {
                sol.push_back({col, row});
                row++;
            }
            col++;
            row = s[1];
        }
        return sol;
    }
};

int main() {

    return 0;
}