memo = {}


def memoize(f):
    def inner(a, b, c, d):
        x = str(b)+str(c)+str(d)
        if x not in memo:
            memo[x] = f(a, b, c, d)
        return memo[x]
    return inner


@memoize
def solve(digits_of_n, i, sum, tight):
    if i == len(digits_of_n):
        return sum
    else:
        k = digits_of_n[i] if tight else 9
        ans = 0
        for j in range(0, k+1):
            istight = tight if digits_of_n[i] == j else False
            ans += (solve(digits_of_n, i+1, sum+j, istight))

        return ans


def hc(a, b):
    if a != "0":
        a = str(int(a)-1)
    digits_of_n = map(int, list(a))
    x = solve(digits_of_n, 0, 0, True)
    memo.clear()
    digits_of_n = map(int, list(b))
    y = solve(digits_of_n, 0, 0, True)
    memo.clear()
    print y - x

while True:
    a, b = raw_input().strip().split()
    if a == "-1":
        break
    hc(a, b)
