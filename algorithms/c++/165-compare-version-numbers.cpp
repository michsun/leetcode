// https://leetcode.com/problems/compare-version-numbers/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        if (version1 == version2) return 0;
        int m = version1.size(), n = version2.size();
        int p = 0, q = 0;
        
        while(p < m || q < n) {
            string buffer1 = "", buffer2 = "";
            int num1 = 0, num2 = 0;
            while(p < m && version1[p] != '.') {
                if (version1[p] != '0' || buffer1.size() > 0)
                    buffer1 += version1[p];
                p++;
            }
            while(q < n && version2[q] != '.') {
                if (version2[q] != '0' || buffer2.size() > 0)
                    buffer2 += version2[q];
                q++;
            }
            if (buffer1.size() > 0)
                num1 = stoi(buffer1);
            if (buffer2.size() > 0)
                num2 = stoi(buffer2);
            
            if (num1 < num2) return -1;
            else if (num1 > num2) return 1;
            
            p++; q++;
        }
        return 0;
    }
};

int main() {

    return 0;
}