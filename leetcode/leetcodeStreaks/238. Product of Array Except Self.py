import numpy as np
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = []

        # prefix product
        prefex = [1] * n 
        for i in range(1,len(nums)):
            prefex[i] = prefex[i-1] * nums[i-1]

        # suffix product
        suffix = 1
        for i in range(n -1,-1 ,-1 ):
            result.append(prefex[i] * suffix)
            suffix = suffix * nums[i]

        return result[::-1]