import sys

with open('in.txt') as f:
    n = int(f.readline().strip())
    adj = [[0]*n for i in range(0, n)]
    
    for line in f:
        a, b = map(int, line.strip().split())       
        adj[b-1][a-1] = 1
        adj[a-1][b-1] = 1

for row in adj:
    print row
