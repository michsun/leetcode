// https://leetcode.com/problems/car-pooling/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> locations(1001, 0);
        for (int i = 0; i < trips.size(); i++) {
            int cap = trips[i][0];
            int from = trips[i][1];
            int to = trips[i][2];
            for (int j = from; j < to; j++) {
                locations[j] += cap;
                if (locations[j] > capacity)
                    return false;
            }
        }
        return true;
    }
};

int main() {

    return 0;
}