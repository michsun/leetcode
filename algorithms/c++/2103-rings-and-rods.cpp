// https://leetcode.com/problems/rings-and-rods/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPoints(string rings) {
        if (rings.size() < 6) return 0;
        
        vector<vector<int>> mem(10, vector<int>(3,0));
        for (int i = 0; i < rings.size()/2; i++) {
            char col = rings[i*2];
            int rod = rings[i*2+1] - '0';
            switch(col) {
                case 'R':
                    mem[rod][0] = 1;
                    break;
                case 'G':
                    mem[rod][1] = 1;
                    break;
                case 'B':
                    mem[rod][2] = 1;
                    break;
            }
        }
        
        int count = 0;
        for (int i = 0; i < 10; i++) {
            if ((mem[i][0] + mem[i][1] + mem[i][2]) == 3)
                count++;
        }
        return count;
    }
};

int main() {

    return 0;
}