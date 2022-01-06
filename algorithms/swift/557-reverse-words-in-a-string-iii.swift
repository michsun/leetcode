// https://leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution {
    func reverseWords(_ s: String) -> String {
        var s = Array(s)
        var start = 0
        var end = 0
        
        for i in 1..<s.count {
            if (s[i] == " ") {
                while(start < end) {
                    s.swapAt(start, end)
                    start += 1
                    end -= 1
                }
                start = i + 1
                end = i + 1
            } else {
                end = i
            }
        }
        while(start < end) {
            s.swapAt(start, end)
            start += 1
            end -= 1
        }
        
        return String(s)
    }
}
