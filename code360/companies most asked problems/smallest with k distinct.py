'''
Problem statement
Given an array 'A' consisting of 'N' integers, find the smallest subarray of 'A' containing exactly 'K' distinct integers.

Note :
If more than one such contiguous subarrays exist, consider the subarray having the smallest leftmost index.

For example - if A is [1, 2, 2, 3, 1, 3 ] and k = 2 then the subarrays: [1,2], [2,3], [3,1], [1,3] are the smallest subarrays containing 2 distinct elements. In this case, we will consider the starting and ending index of subarray [1,2] i.e. 0 and 1.

'''
from typing import List
from collections import defaultdict

def smallestSubarrayWithKDistinct(arr: List[int], k: int) -> List[int]:
    n = len(arr)
    if k > n or n == 0:
        return [-1]

    num_count = defaultdict(int)
    left = 0
    min_length = float('inf')
    min_left = 0
    min_right = 0
    curr_unique_count = 0

    for right in range(n):
        if num_count[arr[right]] == 0:
            curr_unique_count += 1
        num_count[arr[right]] += 1

        while curr_unique_count == k:
            if right - left + 1 < min_length:
                min_length = right - left + 1
                min_left = left
                min_right = right

            num_count[arr[left]] -= 1
            if num_count[arr[left]] == 0:
                curr_unique_count -= 1
            left += 1

    return [min_left, min_right] if min_length != float('inf') else [-1]


