// https://leetcode.com/problems/longest-common-prefix/

class Solution {
    func longestCommonPrefix(_ strs: [String]) -> String {
        var sol: String = strs[0]
        for i in 1..<strs.count {
            let curr = Array(strs[i])
            let prefix = Array(sol)
            var pos = 0
            while pos < prefix.count && pos < curr.count && curr[pos] == prefix[pos] {
                pos += 1
            }
            if pos == 0 { return "" }
            if pos < prefix.count {
                sol = String(prefix[0..<pos])
            }
        }
        return sol
    }
}