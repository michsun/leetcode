// https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        if (arr.size() < k) return 0;
        int changes = 0;
        for (int j = 0; j < k; j++) {
            vector<int> sub;
            int size = 0;
            for (int i = j; i < arr.size(); i += k) {
                if (sub.empty() || sub[sub.size()-1] <= arr[i]) {
                    sub.push_back(arr[i]);
                } else {
                    auto it = upper_bound(sub.begin(), sub.end(), arr[i]); // Iterator pointing to the first element in the range greater than arr[i] 
                    *it = arr[i]; // Replaces number with arr[i]
                }
                size++;
            }
            changes += size - sub.size();
        }
        return changes;
    }
};

int main() {

    return 0;
}