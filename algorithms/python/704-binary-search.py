# https://leetcode.com/problems/binary-search/
from typing import List

class Solution:
    # Recursive
    def search(self, nums: List[int], target: int) -> int:
        def binarySearch(l, r):
            if (l > r):
                return -1
            mid = int((l+r)/2)
            if (nums[mid]==target):
                return mid
            elif (nums[mid] > target):
                return binarySearch(l, mid-1)
            else:
                return binarySearch(mid+1, r)
        return binarySearch(0, len(nums)-1)
    
    # Iterative
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums)-1
        while(l <= r):
            mid = int((l+r)/2)
            if (nums[mid] == target):
                return mid
            elif (nums[mid] > target):
                r = mid-1
            else:
                l = mid+1
        return -1
