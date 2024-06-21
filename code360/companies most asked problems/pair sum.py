from os import *
from sys import *
from collections import *
from math import *

def pairSum(arr, s):
    
    map_ = defaultdict(int)
    pairs = []

    for num in arr:
        diff = s - num

        if map_[diff] > 0:
            #pair exists:
            for _ in range(map_[diff]):
                pairs.append((min(num,diff),max(num,diff)))
            map_[num] += 1
        else:
            map_[num] += 1


    return sorted(pairs)
