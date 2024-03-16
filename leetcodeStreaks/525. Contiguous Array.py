class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        max_len = 0
        sum = 0
        mp = {}

        for i,num in enumerate(nums):
            sum += 1 if num == 1 else -1
            if sum == 0:
                max_len = i + 1
            elif sum in mp:
                max_len = max(max_len,i-mp[sum])
            else:
                mp[sum] = i

        return max_len
                
            
                
        