memo = {}


def memoize(f):

    def inner(a, b, c):
        key = a + "_" + b + "_" + c
        if key not in memo:
            memo[key] = f(a, b, c)
        return memo[key]
    return inner


@memoize
def recursive(a, b, c):
    if c == "" and b != glb and a != gla:
        return 1
    elif c == "" and (b == glb or a == gla):
        return 0
    else:
        ans = 0
        index = a.find(c[0])
        while(index != -1):
            ans = (ans + recursive(a[index + 1:], b, c[1:])) % 1000000007
            index = a.find(c[0], index + 1)

        index = b.find(c[0])
        while(index != -1):
            ans = (ans + recursive(a, b[index + 1:], c[1:])) % 1000000007
            index = b.find(c[0], index + 1)
        return ans


gla, glb, glc = input().strip().split()

for each in gla:
    print(each)
# print(recursive(gla, glb, glc))
