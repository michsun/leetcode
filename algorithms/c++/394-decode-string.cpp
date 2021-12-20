// https://leetcode.com/problems/decode-string/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeString(int& i, string& s) {
        string sol;
        
        while(i < s.size() && s[i] != ']') {
            if (!isdigit(s[i])) {
                sol += s[i++];
            } else {
                int n = 0;
                while(isdigit(s[i])) {
                    n = n*10 + s[i++] - '0';
                }
                
                i++; // Skip '['
                string sub = decodeString(i, s);
                i++; // Skip ']'
                
                while(n--) {
                    sol += sub;
                }
            }
        }
        return sol;
    }
    
    string decodeString(string s) {
        int i = 0;
        return decodeString(i, s);
    }
};

int main() {

    return 0;
}