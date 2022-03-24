// https://leetcode.com/problems/boats-to-save-people/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int count = 0;
        int p = 0, q = people.size()-1;
        while(p <= q) {
            int back = people[q];
            if (p < q && (back + people[p]) <= limit) 
                p++;
            count++;
            q--;
        }
        return count;
    }
};

int main() {

    return 0;
}