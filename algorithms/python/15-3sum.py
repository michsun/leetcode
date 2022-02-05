# https://leetcode.com/problems/3sum/

from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3: 
            return []
        sol = []
        nums.sort()
        for i in range(0, len(nums)-2):
            if nums[i] > 0:
                return sol
            if i > 0 and nums[i] == nums[i-1]:
                continue
            l = i+1
            r = len(nums)-1
            while(l < r):
                total = nums[i] + nums[l] + nums[r]
                if total == 0:
                    sol.append([nums[i], nums[l], nums[r]])
                    while(l < len(nums)-1 and nums[l+1] == nums[l]):
                        l += 1
                    while(r > i and nums[r-1] == nums[r]):
                        r -= 1
                    l += 1
                    r -= 1
                elif total < 0:
                    l += 1
                else:
                    r -= 1
        return sol
