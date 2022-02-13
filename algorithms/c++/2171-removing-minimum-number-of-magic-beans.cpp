// https://leetcode.com/problems/removing-minimum-number-of-magic-beans/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        if (beans.size() == 1) return 0;
        int n = beans.size();
        sort(beans.begin(), beans.end());
        
        long long sum = 0;
        for (int i = 0; i < n; i++)
            sum += beans[i];
        
        long long minRemove = sum; 
        int prevBase = 0; 
        long long prevBaseSum = 0; 
        int i = 0;
        
        while(i < n) {
            int base = beans[i];
            sum = sum - (long long)(n-i) * (long long)(base - prevBase) + prevBaseSum;
            minRemove = min(minRemove, sum);
            
            prevBaseSum = 0;
            while(i < n-1 && beans[i] == beans[i+1]) 
                prevBaseSum += beans[i++];
            prevBaseSum += beans[i++];
            
            prevBase = base;
        }
        return minRemove;
    }
};

int main() {

    return 0;
}