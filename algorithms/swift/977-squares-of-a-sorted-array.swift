// https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution {
    func sortedSquares(_ nums: [Int]) -> [Int] {
        let n: Int = nums.count
        var sol = [Int](repeating: 0, count: n)
        
        var p = 0
        var q = n-1;
        var pos = n-1;
        
        while(pos >= 0) {
            if (abs(nums[p]) >= abs(nums[q])) {
                sol[pos] = nums[p] * nums[p];
                p += 1;
            } else {
                sol[pos] = nums[q] * nums[q];
                q -= 1;
            }
            pos -= 1;
        }
        return sol
    }
}
