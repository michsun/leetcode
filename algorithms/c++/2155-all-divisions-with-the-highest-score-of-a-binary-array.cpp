// https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) 
            sum += nums[i];
        
        int maxScore = -1;
        vector<int> maxIndices;
        
        int scoreLeft = 0, scoreRight = sum, divisionScore;
        for (int i = 0; i <= n; i++) {
            if (i > 0) {
                scoreLeft += nums[i-1] == 0 ? 1 : 0;
                scoreRight -= nums[i-1] == 1 ? 1 : 0;
            }
            divisionScore = scoreLeft + scoreRight;
            if (divisionScore > maxScore) {
                maxScore = divisionScore;
                maxIndices = {i};
            } else if (divisionScore == maxScore) {
                maxIndices.push_back(i);
            }
        }
        return maxIndices;
    }
};

int main() {

    return 0;
}