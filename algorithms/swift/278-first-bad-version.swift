// https://leetcode.com/problems/first-bad-version/

/**
 * The knows API is defined in the parent class VersionControl.
 *     func isBadVersion(_ version: Int) -> Bool{}
 */

class Solution : VersionControl {
    func firstBadVersion(_ n: Int) -> Int {
        if (isBadVersion(1)) {
            return 1
        }
        var mid = Int()
        var l = 2, r = n
        while(l <= r) {
            mid = (l+r)/2
            if (isBadVersion(mid) && !isBadVersion(mid-1)) {
                return mid
            }
            if (isBadVersion(mid)) {
                r = mid-1
            } else {
                l = mid+1
            }
        }
        return -1
    }
}
