from os import *
from sys import *
from collections import *
from math import *

def calculateMaximisedSum(arr1, arr2, N):
    
    dp = [[0 for _ in range(2)] for _ in range(N)]

    # base case 
    dp[0][0] = abs(arr1[0] - arr2[0])
    dp[0][1] = abs(arr1[0] - arr2[0])

    # Fill the dp table
    for i in range(1, N):
        dp[i][0] = abs(arr1[i] - arr2[i]) + max(dp[i-1][0] + abs(arr1[i] - arr2[i-1]), dp[i-1][1] + abs(arr1[i] - arr1[i-1]))
        dp[i][1] = abs(arr1[i] - arr2[i]) + max(dp[i-1][0] + abs(arr2[i] - arr2[i-1]), dp[i-1][1] + abs(arr2[i] - arr1[i-1]))
    
    # Return the maximum value from the last row of the dp table
    return max(dp[N-1][0], dp[N-1][1])