// https://leetcode.com/problems/add-strings/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        stack<int> totalSum;
        int p = num1.size()-1, q = num2.size()-1;
        int carryOver = 0;
        
        while(p >= 0 || q >= 0) {
            int sum = 0;
            if (p >= 0 && q >= 0) {
                sum = num1[p] - '0' + num2[q] - '0' + carryOver;
                p--; q--;
            } else if (p >= 0 && q < 0) {
                sum = num1[p] - '0' + carryOver;
                p--;
            } else if (q >= 0 && p < 0) {
                sum = num2[q] - '0' + carryOver;
                q--;
            }
            carryOver = sum / 10;
            totalSum.push(sum % 10);
        }
        if (carryOver != 0) totalSum.push(carryOver);
        
        string ans;
        while(!totalSum.empty()) {
            ans.push_back(totalSum.top() + '0');
            totalSum.pop();
        }
        return ans;
    }
};

int main() {

    return 0;
}