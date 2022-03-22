// https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string sol = string(n,'z');
        int kv = n * 26;
        int i = 0;
        while(kv - k > 0) {
            if (kv - k >= 26) {
                sol[i] = 'a';
                kv -= 25;
            } else {
                sol[i] -= (kv - k);
                kv -= (kv - k);
            }
            i++;
        }
        return sol;
    }
};

int main() {

    return 0;
}