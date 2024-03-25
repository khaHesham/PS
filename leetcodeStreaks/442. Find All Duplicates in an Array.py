class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        duplicates = set()
        mp = {}
        for num in nums:
            if num in mp.keys():
                duplicates.add(num)
            
            mp[num] = 1

        return duplicates

        