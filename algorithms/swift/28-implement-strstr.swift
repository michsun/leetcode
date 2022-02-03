// https://leetcode.com/problems/implement-strstr/submissions/

class Solution {
    
    // KMP Solution
    func strStr(_ haystack: String, _ needle: String) -> Int {
        if haystack == needle || needle.isEmpty { return 0 }
        if haystack.count <= needle.count || haystack.isEmpty { return -1 }
        
        let pattern = Array(needle)
        let text = Array(haystack)
        
        // Preprocessing - compute prefix
        var pi = [Int](repeating:0, count:pattern.count)
        var p = 0
        for i in 1..<pattern.count {
            while p > 0 && pattern[i] != pattern[p] {
                p = pi[p-1]
            }
            if pattern[i] == pattern[p] {
                p += 1
            } 
            pi[i] = p
        }
        // Matching
        var q = 0
        for i in 0..<text.count {
            while (q > 0 && pattern[q] != text[i]) {
                q = pi[q-1]
            }
            if (pattern[q] == text[i]) {
                q += 1
                if (q == pattern.count) { 
                    return i - pattern.count + 1
                }
            }
        }
        return -1
    }
}
