class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        f = 0
        x = 0
        m = {}
        n_jobs = len(tasks)

        for c in tasks:

            if c in m:
                m[c] += 1
                
                if f < m[c]:
                    f = m[c]
            else:
                m[c] = 1

        for a in m.values():
            if f == a:
                x += 1

        return max((f-1)*(n + 1) + x,n_jobs)