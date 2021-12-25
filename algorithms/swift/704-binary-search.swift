// https://leetcode.com/problems/binary-search/submissions/

class Solution {
    func search(_ nums: [Int], _ target: Int) -> Int {
        func binarySearch(_ l: Int, _ r: Int) -> Int {
            if (l > r) { 
                return -1
            }
            let mid: Int = (l+r)/2
            if (nums[mid] == target) { 
                return mid
            }
            if (nums[mid] > target) {
                return binarySearch(l, mid-1)
            }
            return binarySearch(mid+1, r)
        }
        return binarySearch(0, nums.count-1)
    }
}
