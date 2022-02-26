// https://leetcode.com/problems/count-of-smaller-numbers-after-self/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // void merge(vector<pair<int,int>>& vec, vector<int>& counts, int l, int mid, int r) {
    //     int p = l, q = mid+1;
    //     while(p <= mid) {
    //         if (vec[p].first > vec[q].first) {
    //             swap(vec[p], vec[q]);
    //             counts[vec[q].second]++;
    //             while(q+1 <= r && vec[q].first > vec[q+1].first) {
    //                 swap(vec[q], vec[++q]);
    //                 counts[vec[q].second]++;
    //             }
    //             q = mid+1;
    //         }
    //         p++;
    //     }
    // }
    
    void merge(vector<pair<int,int>>& vec, vector<int>& counts, int l, int mid, int r) {
        int n = r - l + 1;
        vector<pair<int,int> > temp(n);
        int p = l, q = mid+1;
        int i = 0;
        while(p <= mid && q <= r) {
            if (vec[p].first <= vec[q].first) {
                // if (l+i > p)
                counts[vec[p].second] += l+i - p;
                temp[i++] = vec[p++];
            } else {
                // if (l+i > q)
                //     counts[vec[q].second] += l+i - q;
                temp[i++] = vec[q++];
            }
        }
        
        while(p <= mid) {
            counts[vec[p].second] += l+i - p;
            temp[i++] = vec[p++];
        }
        while(q <= r) {
            temp[i++] = vec[q++];
        }
        
        for (int j = 0; j < n; j++) 
            vec[l+j] = temp[j];
    }
    
    void mergeSort(vector<pair<int,int>>& vec, vector<int>& counts, int l, int r) {
        if (l < r) {
            int mid = (l+r)/2;
            mergeSort(vec, counts, l, mid);
            mergeSort(vec, counts, mid+1, r);
            merge(vec, counts, l, mid, r);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n);
        if (n == 1) return counts;
        
        vector<pair<int,int>> vec(n);
        for(int i = 0; i < n; i++) 
            vec[i] = make_pair(nums[i], i);
        
        mergeSort(vec, counts, 0, n-1);
        return counts;
    }
};

int main() {

    return 0;
}