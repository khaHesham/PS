class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        
        nums1 = set(nums1)
        nums2 = set(nums2)

        min1 = -1
        min2 = -1

        for i in nums1:
            if i in nums2:
                min1 = i
                break

        for j in nums2:
            if j in nums1:
                min2 = j
                break
        
        return min(min1, min2)