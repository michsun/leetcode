// https://leetcode.com/problems/count-integers-with-even-digit-sum/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countEven(int num) {
        int count = 0, n = 0;
        while(num > 1) {
            string s = to_string(num);
            for (auto& c: s) 
                n += c - '0';
            if (n % 2 == 0) count++;
            n = 0;
            num--;
        }
        return count;
    }
};

int main() {

    return 0;
}