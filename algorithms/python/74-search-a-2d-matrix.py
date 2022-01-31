# https://leetcode.com/problems/search-a-2d-matrix/

from typing import List

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        l = 0
        r = len(matrix)-1
        while l <= r:
            mid = int((l+r)/2)
            if matrix[mid][0] == target:
                return True
            if matrix[mid][0] < target:
                l = mid+1
            else:
                r = mid-1
        row = r if r >= 0 else 0
        
        l = 0
        r = len(matrix[0])-1
        while l <= r:
            mid = int((l+r)/2)
            if matrix[row][mid] == target:
                return True
            if matrix[row][mid] < target:
                l = mid+1
            else:
                r = mid-1
        return False
