class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mp = {}
        for i in range(len(s)):
            if(s[i] in mp and mp[s[i]] != t[i]) or (s[i] not in mp and t[i] in mp.values()):
                return False
            mp[s[i]] = t[i]
        return True

        