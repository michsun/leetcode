// https://leetcode.com/problems/last-stone-weight/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for (auto &e: stones)
            q.push(e);
        while(q.size() >= 2) {
            int y = q.top(); 
            q.pop();
            int x = q.top();
            q.pop();
            if (y-x > 0)
                q.push(y-x);
        }
        if (q.empty())
            return 0;
        return q.top();
    }
};

int main() {

    return 0;
}