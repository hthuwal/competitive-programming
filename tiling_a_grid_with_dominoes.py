def memo(f):
    memo = {}

    def inner(w):
        if w in memo:
            return memo[w]
        else:
            memo[w] = f(w)
            return memo[w]
    return inner


@memo
def ans(w):
    if(w <= 1):
        return 1
    if(w == 2):
        return 5
    if(w == 3):
        return 11
    res = ans(w-1)+5*ans(w-2)+ans(w-3)-ans(w-4)
    return res


t = int(input())
for i in range(1, t+1):
    n = int(input())
    print i, ans(n)
    t -= 1
