from typing import List

def getTrappedWater(arr: List[int], n: int) -> int:

    left = [0] * n
    right = [0] * n

    max_1 = float('-inf')
    max_2 = float('-inf')

    # left max height
    for i in range(0,len(arr),1):
        max_1 = max(max_1,arr[i])
        left[i] = max_1


    # right max height
    for i in range(len(arr)-1,-1,-1):
        max_2 = max(max_2,arr[i])
        right[i] = max_2


    water = 0
    for i in range(len(arr)):
        water += min( left[i], right[i] ) - arr[i]
        
    return water