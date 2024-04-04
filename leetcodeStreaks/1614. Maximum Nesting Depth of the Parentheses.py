class Solution:
    def maxDepth(self, s: str) -> int:
        depth = 0
        maxd = 0
        for char in s:
            if char == "(":
                depth += 1
                
            if char == ")":
                maxd = max(maxd, depth)
                depth -= 1

        return maxd