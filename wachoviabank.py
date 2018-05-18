t = int(raw_input().strip())

memo = {}


def memoize(f):
    def inner(w, p, c):
        x = str(w)+str(p)+str(c)
        if x not in memo:
            memo[x] = f(w, p, c)
        return memo[x]
    return inner


@memoize
def knapsack(w, p, c):
    if c < 0:
        return 0
    elif len(w) == 0:
        return 0
    else:
        a = knapsack(w[:-1], p[:-1], c)
        if c >= w[-1]:
            b = p[-1] + knapsack(w[:-1], p[:-1], c-w[-1])
            return a if a > b else b
        return a

while(t > 0):
    memo.clear()
    k, m = map(int, raw_input().strip().split())
    w = []
    p = []
    for i in range(0, m):
        a, b = map(int, raw_input().strip().split())
        w.append(a)
        p.append(b)
    print "Hey stupid robber, you can get %d." % knapsack(w, p, k)
    t -= 1
