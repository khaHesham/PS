class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
        knows = {0, firstPerson} # set for people knowing the secret
        for _, grp in groupby(sorted(meetings, key=lambda x: x[2]), key=lambda x: x[2]): 
            stack = set()
            graph = defaultdict(list)
            for x, y, _ in grp:     
                graph[x].append(y)
                graph[y].append(x)
                if x in knows: stack.add(x)
                if y in knows: stack.add(y)
                    
            stack = list(stack)
            # BFS Traversal 
            while stack: 
                x = stack.pop()
                for y in graph[x]: 
                    if y not in knows: 
                        knows.add(y)
                        stack.append(y)
        return knows