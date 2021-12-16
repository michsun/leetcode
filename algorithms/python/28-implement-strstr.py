# https://leetcode.com/problems/implement-strstr/submissions/

class Solution(object):
    
    # Naïve solution
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if needle == "": return 0
        if len(haystack) < len(needle): return -1
        
        for i in range(0,len(haystack)-len(needle)+1):
            if haystack[i: i+len(needle)] == needle:
                return i
        return -1
            
    # KMP Solution
    def strStr2(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if needle == "": return 0
        if len(haystack) < len(needle): return -1
        
        # Preprocessing
        pi = [0]
        i = 0
        for j in range(1, len(needle)):
            while i > 0 and needle[i] != needle[j]:
                i = pi[i-1]
            if needle[j] == needle[i]:
                i += 1
            pi.append(i)
        
        # Matching
        q = 0
        for k in range(0, len(haystack)):
            while q > 0 and haystack[k] != needle[q]:
                q = pi[q-1]
            if needle[q] == haystack[k]:
                q += 1
                if (q == len(needle)):
                    return k - len(needle) + 1
        return -1