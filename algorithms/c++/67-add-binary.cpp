// https://leetcode.com/problems/add-binary/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // With stack
    string addBinary(string a, string b) {
        stack<int> stk;
        int carryOver = 0;
        int n = a.size()-1;
        int m = b.size()-1;
        while(n >= 0 || m >= 0) {
            int curr = carryOver;
            if (n >= 0)
                curr += a[n] - '0';
            if (m >= 0)
                curr += b[m] - '0';
            
            carryOver = curr/2;
            stk.push(curr%2);
            n--; m--;
        }
        if (carryOver == 1) stk.push(1);
        
        string sol;
        while(!stk.empty()) {
            sol.push_back(stk.top() + '0');
            stk.pop();
        }
        return sol;
    }
    
    // Without stack
    string addBinary(string a, string b) {
        string sol = "";
        int carryOver = 0;
        int n = a.size()-1;
        int m = b.size()-1;
        
        while(n >= 0 || m >= 0) {
            int curr = carryOver;
            if (n >= 0)
                curr += a[n] - '0';
            if (m >= 0)
                curr += b[m] - '0';
            
            carryOver = curr/2;
            sol = char(curr%2 + '0') + sol;
            n--; m--;
        }
        if (carryOver == 1) sol = char(carryOver + '0') + sol;
        
        return sol;
    }
};

int main() {

    return 0;
}