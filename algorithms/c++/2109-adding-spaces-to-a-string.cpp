// https://leetcode.com/problems/adding-spaces-to-a-string/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Method 1
    string addSpaces(string s, vector<int>& spaces) {
        string str = "";
        int p = 0;
        for (int i = 0; i < s.size(); i++) {
            if (p == spaces.size()) { str += s[i]; continue; }
            if (i == spaces[p]) {
                str += " ";
                p++;
            } 
            str += s[i];
        }
        return str;
    }
    
    // Method 2
    string addSpaces(string s, vector<int>& spaces) {
        string str = "";
        int prev = 0;
        for (int i = 0; i < spaces.size(); i++) {
            str += s.substr(prev, spaces[i]-prev) + ' ';
            prev = spaces[i];
        }
        str += s.substr(prev, s.size()-prev);
        return str;
    }
};

int main() {

    return 0;
}