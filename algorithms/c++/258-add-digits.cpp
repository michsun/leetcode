// https://leetcode.com/problems/add-digits/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        string s;
        while (num % 10 != num) {
            s = to_string(num);
            num = 0;
            for (auto c: s)
                num += (c-'0');
        }
        return num;
    }
};

int main() {

    return 0;
}