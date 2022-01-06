// https://leetcode.com/problems/move-zeroes/

class Solution {
    func moveZeroes(_ nums: inout [Int]) {
        var p = 0
        for i in 0..<nums.count {
            if (nums[i] != 0) {
                nums[p] = nums[i]
                if (p != i) {
                    nums[i] = 0
                }
                p += 1
            }
        }
    }
}
