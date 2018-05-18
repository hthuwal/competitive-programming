m = 1000000007

def memoize(f):
    memo = {}
    def inner(x, y):
        if (x, y) not in memo:
            memo[(x, y)] = f(x, y)
        return memo[(x, y)]
    return inner


@memoize             
def ans(x, y):
    if x == 0 and y == 0:
        return 1 % m
    elif x == 0:
        return ans(x, y-1)
    elif y == 0:
        return ans(x-1, y)
    else:
        return (ans(x, y-1) + ans(x-1, y)) % m


t = int(raw_input().strip())
while t>0:
    x, y = map(int, raw_input().strip().split())
    print ans(x, y)
    t = t - 1