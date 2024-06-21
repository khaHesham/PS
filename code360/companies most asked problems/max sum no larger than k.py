from os import *
from sys import *
from collections import *
from math import *
from sortedcontainers import SortedList

from typing import List


def sumNoLargerThanK(arr: List, k: int) -> int:
    # initialize max sum as negative infinity
    max_sum = float('-inf')

    prefixSum = 0
    # sorted list for handling BST functionality
    prefixSums = SortedList([0])

    for num in arr:
        prefixSum += num
        # find smallest target 
        target = prefixSum - k

        # Binary search in sorted list to find the smallest prefix >= target
        idx = prefixSums.bisect_left(target)
        if idx < len(prefixSums):
            max_sum = max(max_sum,prefixSum - prefixSums[idx])
        
        prefixSums.add(prefixSum)

    return max_sum


def maxSum(k: int, mat: List[List[int]]) -> int:

    max_sum = float('-inf')

    rows = len(mat)
    cols = len(mat[0]) if mat else 0

    for start_row in range(rows):
        sum_cols = [0] * cols

        for end_row in range(start_row,rows):
            # update column sum for current pair of rows

            for col in range(cols):
                sum_cols[col] += mat[end_row][col]

            # find the max subarray sum no larger than k for the current column sum
            max_sum = max(max_sum,sumNoLargerThanK(sum_cols,k))

    return max_sum


# very good problem and similar to instabug technical exam problem 
# the idea here is how to use binary search to optimize your solution 
# instead of converting it to maximization problem