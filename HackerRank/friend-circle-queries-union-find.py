
parents = {}
size = {}


def find(a):
    x = a
    while(a in parents and parents[a] != a):
        a = parents[a]
    if a not in parents:
        parents[a] = a
        size[a] = 1

    # while(x in parents and parents[x] != x):
    #     temp = x
    #     x = parents[x]
    #     parents[temp] = a
    #     size[x] -= size[temp]
    return a


def union(a, b):
    pa = find(a)
    pb = find(b)
    if (pa != pb):
        if(size[pa] > size[pb]):
            parents[pb] = pa
            size[pa] += size[pb]
            size[pb] = 0
        else:
            parents[pa] = pb
            size[pb] += size[pa]
            size[pa] = 0

q = int(input())
while(q > 0):
    a, b = input().strip().split()
    union(a, b)
    # print(parents)
    # print(size)
    print(max(list(size.values())))
    q -= 1
