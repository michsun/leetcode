// https://leetcode.com/problems/search-insert-position/

class Solution {
    func searchInsert(_ nums: [Int], _ target: Int) -> Int {
        var l = 0, r = nums.count-1
        while(l <= r) {
            var mid: Int = (l+r)/2
            if (nums[mid]==target) { return mid }
            if (nums[mid] > target) { r = mid-1 }
            else { l = mid+1 }
        }
        return l
    }
}
