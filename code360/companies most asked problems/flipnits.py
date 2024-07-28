'''
Problem statement
You are given an array of integers ARR[] of size N consisting of zeros and ones. You have to select a subset and flip bits of that subset. You have to return the count of maximum one’s that you can obtain by flipping chosen sub-array at most once.

A flip operation is one in which you turn 1 into 0 and 0 into 1.

For example:
If you are given an array {1, 1, 0, 0, 1} then you will have to return the count of maximum one’s you can obtain by flipping anyone chosen sub-array at most once, so here you will clearly choose sub-array from the index 2 to 3 and then flip it's bits. So, the final array comes out to be {1, 1, 1, 1, 1} which contains five ones and so you will return 5.
'''

from sys import *
from collections import *
from math import *

def flipBits(arr, n): 
    # Write your code here
    ones = sum(arr)
    max_gain = 0
    current_gain = 0

    # using modified kadane's algorithm to find max sum of subarray
    for bit in arr:
        value = 1 if bit == 0 else -1
        current_gain = max(value, current_gain+value)
        max_gain = max(max_gain,current_gain)


    return max_gain + ones

