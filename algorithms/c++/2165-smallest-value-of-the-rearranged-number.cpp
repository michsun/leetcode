// https://leetcode.com/problems/smallest-value-of-the-rearranged-number/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long smallestNumber(long long num) {
        string s = to_string(num);
        vector<char> nums = {'0','1','2','3','4','5','6','7','8','9'};
        vector<int> count(10,0);
        
        int i = 0;
        if (s[0] == '-') i = 1;
        
        for (i; i < s.size(); i++) 
            count[s[i]-'0']++;
        
        string sol = "";
        if (s[0] == '-') {
            sol += "-";
            int pos = 9;
            while(pos >= 0) {
                sol += string(count[pos], nums[pos]);
                pos--;
            }
        } else {
            int pos = 1;
            if (count[0] > 0) {
                while(pos < 10 && count[pos] == 0) pos++;
                if (pos == 10) return 0;
                sol += string(1, nums[pos]);
                count[pos] -= 1;
                sol += string(count[0], '0');
            } 
            while(pos < 10) {
                sol += string(count[pos], nums[pos]);
                pos++;
            }
        }
        
        return stoll(sol);
    }
};

int main() {

    return 0;
}