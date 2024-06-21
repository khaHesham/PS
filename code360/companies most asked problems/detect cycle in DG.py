from collections import deque,defaultdict

def detectCycleInDirectedGraph(n, edges):
    def dfs(node, graph, visited, rec_stack):
        visited.add(node)
        rec_stack.add(node)

        if node in graph:
            for neighbor in graph[node]:
                if neighbor not in visited:
                    if dfs(neighbor, graph, visited, rec_stack):
                        return True
                elif neighbor in rec_stack:
                    return True

        rec_stack.remove(node)
        return False

    graph = defaultdict(list)

    for u, v in edges:
        graph[u].append(v)

    visited = set()
    rec_stack = set()

    for node in range(n):
        if node not in visited:
            if dfs(node, graph, visited, rec_stack):
                return True

    return False

