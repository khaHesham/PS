import numpy as np
class Solution:
    def pivotInteger(self, n: int) -> int:
        sum = (n + 1) * n // 2
        pivot = np.sqrt(sum)
        return int(pivot) if pivot - math.ceil(pivot) == 0 else -1
                