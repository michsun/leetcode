// https://leetcode.com/problems/intersection-of-two-arrays-ii/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        
        for (int i = 0; i < nums1.size(); i++) {
            if (mp.find(nums1[i]) == mp.end()) {
                mp[nums1[i]] = 1;
            } else {
                mp[nums1[i]]++;
            }
        }
        
        vector<int> intersection;
        for (int j = 0; j < nums2.size(); j++) {
            if (mp.find(nums2[j]) != mp.end()) {
                if (mp[nums2[j]] > 0) {
                    intersection.push_back(nums2[j]);
                    mp[nums2[j]]--;
                }
            }
        }
        return intersection;
    }
};

int main() {

    return 0;
}