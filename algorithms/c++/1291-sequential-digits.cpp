// https://leetcode.com/problems/sequential-digits/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:    
    vector<int> sequentialDigits(int low, int high) {
        vector<int> sol;
        
        // Number of digits
        int nlow = slow.size();
        int nhigh = shigh.size();
        
        for (int i = nlow; i <= nhigh; ++i) {
            // Initialise the first number
            string num = string(i, '0');
            int pos = 0;
            while(pos < i) {
                num[pos] = num[pos] + pos + 1;
                pos++;
            }
            // Check and generate subsequent numbers
            while(num[0]-'0' <= 10-i) {
                if (stoi(num) >= low && stoi(num) <= high) {
                    sol.push_back(stoi(num));
                }
                pos = 0;
                while(pos < i) {
                    num[pos] = num[pos]+1;
                    pos++;
                }
            }
        }
        return sol;
    }
};

int main() {

    return 0;
}