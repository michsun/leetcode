

class Solution {
    func containsDuplicate(_ nums: [Int]) -> Bool {
        var dict = [Int: Int]()
        for num in nums {
            if dict[num] == nil {
                dict[num] = 1
            } else {
                return true
            }
        }
        return false
    }
}