def memoize(f):
    memo = {}

    def inner(n, k):
        if (n, k) not in memo:
            memo[(n, k)] = f(n, k)
        return memo[(n, k)]
    return inner


@memoize
def josephus_problem(n, k):
    if(n == 1):
        return 1
    else:
        return (josephus_problem(n-1, k)+k-1) % n + 1


while (1):
    n, k = raw_input().strip().split()
    n = int(n.strip())
    k = int(k.strip())
    if n == 0 and k == 0:
        break
    print n, k, josephus_problem(n, k)
