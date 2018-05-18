import copy


def dist(a, b):
    return abs(a[0]-b[0])+abs(a[1]-b[1])

memo = {}


def memoize(f):
    def inner(a, b):
        x = str(a)+str(b)
        if x not in memo:
            memo[x] = f(a, b)
        return memo[x]
    return inner


@memoize
def rec(baby, correct):
    if len(baby) == 0:
        return 0
    else:
        option = []
        for i in range(0, len(baby)):
            temp = copy.deepcopy(correct)
            temp.remove(correct[i])
            x = dist(baby[0], correct[i]) + \
                rec(baby[1:], temp)
            option.append(x)
        return min(option)

while True:
    memo.clear()
    n = int(raw_input().strip())
    if n == 0:
        break
    rows = [i for i in range(1, n+1)]
    baby = zip(rows, map(int, raw_input().strip().split()))
    correct = zip(rows, map(int, raw_input().strip().split()))
    print rec(baby, correct)
