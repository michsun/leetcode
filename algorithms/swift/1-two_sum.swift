// https://leetcode.com/problems/two-sum/

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
