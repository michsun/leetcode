// https://leetcode.com/problems/a-number-after-a-double-reversal/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSameAfterReversals(int num) {
        string str = to_string(num);
        
        for (int i = 0; i < str.size()/2; i++)
            swap(str[i], str[str.size()-i-1]);
        // Removes leading zeroes
        int j = 0;
        if (str.size() > 1) {
            while(str[j]=='0') j++;
        }
        str = str.substr(j, str.size()-j);
        for (int i = 0; i < str.size()/2; i++)
            swap(str[i], str[str.size()-i-1]);
        
        if (num == stoi(str)) return true;
        return false;
    }
};

int main() {

    return 0;
}