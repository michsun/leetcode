// https://leetcode.com/problems/numbers-at-most-n-given-digit-set/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        // mem(i) = number of digits <= i
        vector<int> mem(10, 0);
        int digits_pos = 0;
        for (int i = 1; i < 10; i++) {
            if (digits_pos < digits.size() && digits[digits_pos][0] - '0' == i) {
                mem[i] = mem[i-1] + 1;
                digits_pos++;
            } else {
                mem[i] = mem[i-1];
            }
        }
        
        string n_str = to_string(n);
        int n_digits = digits.size();
        int count = 0;
        
        // Cases with same number of digits as n        
        bool val_in_digits = true;
        int j = 0;
        while(j < n_str.size() && val_in_digits) {
            int val = n_str[j]-'0';
            if (val == 0) {
                val_in_digits = false;
            } else {
                count += mem[val-1] * pow(n_digits, n_str.size()-j-1);
                if (mem[val] == mem[val-1]) { // val in digits if mem[val] > mem[val-1]
                    val_in_digits = false;
                }
            }
            j++;
        }
        if (val_in_digits) count++;

        // Cases with less number of digits than n
        int pos = n_str.size()-1;
        while(pos > 0) {
            count += (int) pow(n_digits, pos);
            pos--;
        }
        
        return count;
    }
};

int main() {

    return 0;
}