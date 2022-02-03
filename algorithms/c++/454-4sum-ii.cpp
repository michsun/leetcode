// https://leetcode.com/problems/4sum-ii/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // O(n^2) complexity
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count = 0;
        int n = nums1.size();
        unordered_map<int, int> hash1; // nums1 and nums2
        unordered_map<int, int> hash2; // nums3 and nums4
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sum1 = nums1[i] + nums2[j];
                int sum2 = nums3[i] + nums4[j];
                
                if (hash1.find(sum1) != hash1.end())
                    hash1[sum1] += 1;
                else
                    hash1[sum1] = 1;
                if (hash2.find(sum2) != hash2.end())
                    hash2[sum2] += 1;
                else
                    hash2[sum2] = 1;
            }
        }
        
        for (auto & it: hash1) {
            int num = it.first;
            if (hash2.find(0-num) != hash2.end())
                count += it.second*hash2[0-num];
        }
        return count;
    }

    // Same as above but more efficient code
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count = 0;
        int n = nums1.size();
        unordered_map<int,int> hash1, hash2; // hash1 -> nums1_i + num2_j, hash2 -> nums3_i + nums4_j
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                hash1[nums1[i]+nums2[j]]++;
                hash2[nums3[i]+nums4[j]]++;
            }
        }
        for (auto & it: hash1) {
            if (hash2.find(0-it.first) != hash2.end())
                count += it.second*hash2[0-it.first];
        }
        return count;
    }
};

int main() {

    return 0;
}