# https://leetcode.com/problems/merge-intervals/
from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) == 1:
            return intervals
        intervals.sort()
        solution = []
        rnge = intervals[0]
        for i in range(1, len(intervals)):
            if (rnge[1] < intervals[i][0]):
                solution.append(rnge)
                rnge = intervals[i]
            else: ## (rnge[1] >= intervals[i][0]):
                rnge[1] = max(rnge[1], intervals[i][1])
        solution.append(rnge)
        return solution
            
