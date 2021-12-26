// https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> out;
        
        for (int i = 0; i < s.size(); i++) {
            int j = i; 
            int r = startPos[0];
            int c = startPos[1];
            bool valid = true;
            while (j < s.size() && valid) {
                switch(s[j]) {
                    case 'L':
                        c--;
                        break;
                    case 'R':
                        c++;
                        break;
                    case 'U':
                        r--;
                        break;
                    case 'D':
                        r++;
                        break;
                }
                if (r < n && r >= 0 && c < n && c >= 0)
                    j++; 
                else
                    valid = false;
            }
            out.push_back(j-i); 
        }
        return out;
    }
};

int main() {

    return 0;
}