from os import *
from sys import *
from collections import *
from math import *

from sys import stdin,setrecursionlimit
setrecursionlimit(10**7)

def maxSubarraySum(arr, n) :

    max_ = 0
    curr_sum = 0

    for i in range(0,len(arr)):
        curr_sum += arr[i]
        
        curr_sum = max(curr_sum,0)
        max_ = max(max_, curr_sum)

    return max_

#taking inpit using fast I/O
def takeInput() :
	
    n =  int(input())

    if(n == 0) :
        return list(), n

    arr = list(map(int, stdin.readline().strip().split(" ")))

    return arr, n


#main
arr, n = takeInput()
print(maxSubarraySum(arr, n))
