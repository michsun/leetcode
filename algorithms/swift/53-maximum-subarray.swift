// https://leetcode.com/problems/maximum-subarray/

class Solution {
    func maxSubArray(_ nums: [Int]) -> Int {
        var max_here = 0
        var max_so_far = -10000
        for num in nums {
            max_here = max(num, max_here+num)
            max_so_far = max(max_so_far, max_here)
        }
        return max_so_far
    }
}