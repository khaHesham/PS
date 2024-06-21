from math import *
from collections import *
from sys import *

from typing import List


def setZeros(matrix: List[List[int]]) -> None:
    n = len(matrix)
    m = len(matrix[0]) if matrix else 0

    infected = defaultdict(list)

    for i in range(n):
        for j in range(m):
            if matrix[i][j] == 0:
                # mark this row and col as infected
                infected[i].append(j)
                
    # loop through infected rows and matrix and set all row and col to be infected
    for i in range(n):
        for j in range(m):
            if i in infected.keys():
                matrix[i][j] = 0
            if any(j in values for values in infected.values()):
                matrix[i][j] = 0


