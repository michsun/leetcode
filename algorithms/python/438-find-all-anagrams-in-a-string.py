# https://leetcode.com/problems/find-all-anagrams-in-a-string/

from typing import List

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(s) < len(p): return []
        p_list = [ 0 for i in range(0, 26) ]
        s_list = [ 0 for i in range(0, 26) ]
        sol = []
        
        for i in range(0, len(p)):
            p_list[ord(p[i])-ord('a')] += 1
            s_list[ord(s[i])-ord('a')] += 1
        if p_list == s_list:
            sol.append(0)
            
        for i in range(len(p), len(s)):
            s_list[ord(s[i-len(p)])-ord('a')] -= 1
            s_list[ord(s[i])-ord('a')] += 1
            if p_list == s_list:
               sol.append(i-len(p)+1)
        return sol
        
