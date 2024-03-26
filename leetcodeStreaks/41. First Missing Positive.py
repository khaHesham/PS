class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        # sort the list
                # Swap elements to their correct positions
        for i in range(n):
            while 1 <= nums[i] <= n and nums[nums[i] - 1] != nums[i]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]

        # find first positive missing number
        for i in range(0,n,1):
            if nums[i] != i + 1:
                return i + 1
                
        return n + 1
