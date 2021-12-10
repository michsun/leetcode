# https://leetcode.com/problems/contains-duplicate/
from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        seen = dict()
        for num in nums:
            if num in seen.keys():
                return True
            seen[num] = 1
        return False
