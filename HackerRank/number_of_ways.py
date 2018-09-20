def memoize(f):
    memo = {}

    def inner(a, b, c):
        key = a + b + c
        if key not in memo:
            memo[key] = f(a, b, c)
        return memo[key]
    return inner


@memoize
def recursive(a, b, c):
    if c == "":
        return 1
    else:
        ans = 0
        index = a.find(c[0], 0)
        while(index != -1):
            ans = (ans + recursive(a[index + 1:], b, c[1:])) % 1000000007
            index = a.find(c[0], index + 1)

        index = b.find(c[0], 0)
        while(index != -1):
            ans = (ans + recursive(a, b[index + 1:], c[1:])) % 1000000007
            index = b.find(c[0], index + 1)
        return ans


a, b, c = input().strip().split()
print(recursive(a, b, c))
