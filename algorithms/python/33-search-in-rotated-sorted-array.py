# https://leetcode.com/problems/search-in-rotated-sorted-array/
from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        rot = nums[0]
        l = 0
        r = len(nums)-1
        while l <= r:
            mid = int((l+r)/2)
            if nums[mid] == target:
                return mid
            if target < rot:
                if nums[mid] >= rot or nums[mid] < target:
                    l = mid+1
                else:
                    r = mid-1
            if target >= rot:
                if nums[mid] < rot or nums[mid] > target:
                    r = mid-1
                else: 
                    l = mid+1
        return -1
