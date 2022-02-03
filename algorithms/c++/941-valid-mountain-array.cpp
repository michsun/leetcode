// https://leetcode.com/problems/valid-mountain-array/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() <= 2) return false;
        int l = 1, r = arr.size()-2;
        bool hasPeak = false;
        while(l <= r) {
            if (arr[l] == arr[l-1] || arr[r] == arr[r+1])
                return false;
            if (arr[l] < arr[l-1] && arr[r] < arr[r+1]) // two peaks
                return false;
            if (arr[l] > arr[l-1])
                l++;
            if (arr[r] > arr[r+1])
                r--;
        }
        if (l-r == 1 && (l == arr.size()-1 || r == 0))
            return false;
        if (l-r == 2 || (l-r == 1 && arr[l] != arr[r]))
            return true;
        return false;
    }
};

int main() {

    return 0;
}