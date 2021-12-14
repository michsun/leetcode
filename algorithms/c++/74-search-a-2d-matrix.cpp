// https://leetcode.com/problems/search-a-2d-matrix/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool binarySearchRow(vector<int>& arr, int target, int left, int right) {
        if (left > right) {
            return false;
        }
        int mid = (left + right)/2;
        
        if (arr[mid] == target) {
            return true;
        } else if (target < arr[mid]) {
            return binarySearchRow(arr, target, left, mid-1);
        } else {
            return binarySearchRow(arr, target, mid+1, right);
        }
    }

    // Returns the index of the expected row
    int binarySearchCol(vector<vector<int>>& matrix, int target, int left, int right) {
        if (left > right) {
            if (right == -1) return 0;
            return right;
        }
        int mid = (left + right) / 2;
        if (matrix[mid][0] == target) {
            return mid;
        } else if (target < matrix[mid][0]) {
            return binarySearchCol(matrix, target, left, mid-1);
        } else {
            return binarySearchCol(matrix, target, mid+1, right);
        }
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Search row
        int rowVal = binarySearchCol(matrix, target, 0, matrix.size()-1);
        return binarySearchRow(matrix[rowVal], target, 0, matrix[rowVal].size()-1);
    }
};

int main() {

    return 0;
}