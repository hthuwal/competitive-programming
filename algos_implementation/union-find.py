"""results

Fuddu mistake: Not maintaining global max variable, finding max of all sizes
after each query: => O(q*n) TLE in 8-10 cases

* Now maintain a global variable to store max

1. Basic Union, Basic Find: TLE in one case (Worst case Find can be O(n))
2. Size Weighted Union, Basic Find: Works (Worst case Find can be O(log n)) Proof?
3. Basic Union, Pathe Compression in Find: Works (Worst case Find can O(log n)) Proof?
4. Size Weighted Union, Pathe Compression Find: Works
    (Complexity becomes log*(n))

"""
import timeit

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


def find_path_compression(a):
    global max_size
    x = a
    while(a in parents and parents[a] != a):
        a = parents[a]
    if a not in parents:
        parents[a] = a
        size[a] = 1
        if size[a] > max_size:
            max_size = size[a]

    while(x in parents and parents[x] != x):
        temp = x
        x = parents[x]
        parents[temp] = a
        size[x] -= size[temp]
    return a


def union_basic(a, b):
    global max_size
    pa = find_basic(a)
    pb = find_basic(b)
    if pa != pb:
        parents[pa] = pb
        size[pb] += size[pa]
        size[pa] = 0
        if(size[pb] > max_size):
            max_size = size[pb]


def union_find_path_compression(a, b):
    global max_size
    pa = find_path_compression(a)
    pb = find_path_compression(b)
    if pa != pb:
        parents[pa] = pb
        size[pb] += size[pa]
        size[pa] = 0
        if(size[pb] > max_size):
            max_size = size[pb]


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


def size_weighted_union_find_path_compression(a, b):
    global max_size
    pa = find_path_compression(a)
    pb = find_path_compression(b)

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


def execute(queries, func):
    for a, b in queries:
        func(a, b)


q = int(input())
queries = []
while(q > 0):
    a, b = input().strip().split()
    queries.append((a, b))
    q -= 1

# execute(queries, union_basic)
# execute(queries, size_weighted_union)
# execute(queries, size_weighted_union_find_path_compression)


def wrapper(func, *args, **kwargs):
    def wrapped():
        return func(*args, **kwargs)
    return wrapped


parents.clear()
size.clear()
max_size = 1
wrapped = wrapper(execute, queries, union_basic)
print("Basic Union Find: ", timeit.timeit(wrapped, number=100) / 100.0)

parents.clear()
size.clear()
max_size = 1
wrapped = wrapper(execute, queries, size_weighted_union)
print("Size Weighted Union, Basic Find: ", timeit.timeit(wrapped, number=100) / 100.0)

parents.clear()
size.clear()
max_size = 1
wrapped = wrapper(execute, queries, union_find_path_compression)
print("Basic Union, Path compression in find: ", timeit.timeit(wrapped, number=100) / 100.0)

parents.clear()
size.clear()
max_size = 1
wrapped = wrapper(execute, queries, size_weighted_union_find_path_compression)
print("Size Weighted Union,, Path compression in find: ", timeit.timeit(wrapped, number=100) / 100.0)
