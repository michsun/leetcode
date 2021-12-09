/*
Link: https://leetcode.com/problems/two-sum/

Time Complexity: O(n)
*/

class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var map = [Int: Int]()
        for i in 0..<nums.count {
            if let found = map[target - nums[i]] {
                return [found, i]
            }
            map[nums[i]] = i
        }
        return [Int]()
    }
}


var nums = [1, 3, 5, 11]
var target = 8
var sol = Solution().twoSum(nums, target)
print(sol)
