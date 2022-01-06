// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
    func twoSum(_ numbers: [Int], _ target: Int) -> [Int] {
        var p = 0
        var q = numbers.count-1
        var sum = 0
        
        while (p < q) {
            sum = numbers[p] + numbers[q]
            if (sum == target) {
                return [p+1, q+1]
            }
            if (sum > target) {
                q -= 1
            } else {
                p += 1
            }
        }
        return [-1,-1]
    }
}
