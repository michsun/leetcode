// https://leetcode.com/problems/merge-intervals/

class Solution {
    func merge(_ intervals: [[Int]]) -> [[Int]] {
        if (intervals.count == 1) {
            return intervals
        }
        var intervals = intervals
        intervals.sort {
            $0[0] < $1[0]
        }
        
        var sol = [[Int]]()
        var range = intervals[0]
        for interval in intervals {
            if (range[1] < interval[0]) {
                sol.append(range)
                range = interval
            }
            if (range[1] >= interval[0]) {
                range[1] = max(range[1], interval[1])
            }
        }
        sol.append(range)
        return sol
    }
}
