/*
Link: https://leetcode.com/problems/palindrome-number/

*/

class Solution {
    func isPalindrome(_ x: Int) -> Bool {
        var s = Array(String(x))
        var p = 0
        var q = s.count - 1
        while(p < q) {
            if s[p] != s[q] {
                return false
            }
            p += 1
            q -= 1
        }
        return true
    }
}
