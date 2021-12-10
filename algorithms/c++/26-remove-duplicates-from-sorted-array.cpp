#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) { return 0; }
        int k = 0;
        for(int i = 1; i < nums.size(); i++) {
            if (nums[k] == nums[i]) {
                nums[i] = -101;
            } else {
                k++;
                if (k != i) {
                    nums[k] = nums[i];
                    nums[i] = -101;
                }
            }
        }
        return ++k;
    }
};

int main() {

}