"""
https://www.hackerrank.com/challenges/friend-circle-queries

Using DFS to find all connected components

TLE in 6 test cases
"""
from collections import defaultdict


class Graph:
    def __init__(self):
        self.adj = defaultdict(list)

    def add_edge(self, a, b):
        self.adj[a].append(b)
        self.adj[b].append(a)

    def dfs(self, s, visited):
        size = 0
        stack = []
        stack.append(s)
        while(stack):
            top = stack.pop()
            size += 1
            visited[top] = True
            for nbr in self.adj[top]:
                if not visited[nbr]:
                    stack.append(nbr)
        return size

    def largest_connected_component(self):
        visited = defaultdict.fromkeys(self.adj.keys(), False)
        largest = 1
        for key in visited:
            print(visited)
            if not visited[key]:
                size = self.dfs(key, visited)
                if size > largest:
                    largest = size
        return largest

    def __repr__(self):
        return repr(self.adj)


g = Graph()
q = int(input().strip())
while q:
    a, b = input().strip().split()
    a, b = int(a), int(b)
    g.add_edge(a, b)
    print(g.largest_connected_component())
    # print(g)
    q -= 1
