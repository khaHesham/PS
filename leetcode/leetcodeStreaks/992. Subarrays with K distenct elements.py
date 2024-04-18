class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        
        # count of subarrays at most k
        count1 = self.atMostK(nums, k)

        # count of arrays with at most k - 1
        count2 = self.atMostK(nums, k - 1)

        # return count1 - count 2
        return count1 - count2
    
    def atMostK(self, nums, k):
        ans = 0
        mp = {}
        l = 0
        n = len(nums)
        for r in range(n):
            mp[nums[r]] = mp.get(nums[r], 0) + 1
            while len(mp) > k:
                mp[nums[l]] -= 1
                if mp[nums[l]] == 0:
                    del mp[nums[l]]
                l += 1
            ans += r - l + 1
        return ans