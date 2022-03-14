# https://leetcode.com/problems/simplify-path/

class Solution:
    def simplifyPath(self, path: str) -> str:
        absolute = path.split('/')
        canonical = []
        for a in absolute:
            if a == "." or a == "":
                continue
            if a == ".." and len(canonical) > 0:
                canonical.pop()
            if a != "..":
                canonical.append(a)
                
        output = ""
        for e in canonical:
            output += "/" + e
        if output == "": 
            output = "/"
        return output
