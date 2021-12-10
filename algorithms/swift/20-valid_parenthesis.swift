// https://leetcode.com/problems/valid-parentheses/

class Solution {
    func isValid(_ s: String) -> Bool {
        let dict: [Character: Character] = [
            "(": ")",
            "[": "]",
            "{": "}"
        ]
        let str = Array(s)
        var stack: [Character] = [str[0]]
        var lastPos = 0
        for i in 1..<str.count {
            let currLetter: Character = str[i]
            if lastPos >= 0 && currLetter == dict[stack[lastPos]] {
                stack.removeLast()
                lastPos -= 1
            } else if dict[currLetter] == nil {
                return false
            } else {
                stack.append(currLetter)
                lastPos += 1
            }
        }
        if str.count == 1 || stack.count > 0 { return false }
        return true
    }
}