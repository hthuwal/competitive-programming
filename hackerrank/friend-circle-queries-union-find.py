parents = {}
size = {}
max_size = 1


def find_basic(a):
    global max_size
    x = a
    while(a in parents and parents[a] != a):
        a = parents[a]
    if a not in parents:
        parents[a] = a
        size[a] = 1
        if size[a] > max_size:
            max_size = size[a]

    return a


def size_weighted_union(a, b):
    global max_size
    pa = find_basic(a)
    pb = find_basic(b)

    if (pa != pb):
        if(size[pa] > size[pb]):
            parents[pb] = pa
            size[pa] += size[pb]
            size[pb] = 0
            if(size[pa] > max_size):
                max_size = size[pa]
        else:
            parents[pa] = pb
            size[pb] += size[pa]
            size[pa] = 0
            if(size[pb] > max_size):
                max_size = size[pb]


q = int(input())
while(q > 0):
    a, b = input().strip().split()
    size_weighted_union(a, b)
    print(max_size)
    q -= 1
