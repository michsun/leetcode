# https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums) == 0:
            return [-1,-1]
        l = 0
        r = len(nums)-1
        while l < r:
            mid = (l+r)/2
            if nums[mid] == target and (mid == 0 or nums[mid-1] < target):
                l = mid
            if nums[mid] < target:
                l = mid+1
            else:
                r = mid-1
        if nums[l] != target:
            return [-1,-1]
        
        start = l
        r = len(nums)-1
        while l <= r:
            mid = (l+r)/2
            if nums[mid] == target:
                l = mid+1
            else: # nums[mid] > target:
                r = mid-1
        return [start, r]
        
        
                
