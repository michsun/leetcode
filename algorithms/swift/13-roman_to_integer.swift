/*
Link: https://leetcode.com/problems/roman-to-integer/

*/

class Solution {
    func romanToInt(_ s: String) -> Int {
        let dict: [Character: Int] = [
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        ]
        let strArray = Array(s)
        
        var sol: Int = dict[strArray[0]]!
        var prev: Int = sol
        for i in 1..<strArray.count {
            let curr: Int = dict[strArray[i]]!
            if curr <= prev {
                sol += curr
            } else {
                sol += -2 * prev + curr
            }
            prev = curr
        }
        return sol
    }
}