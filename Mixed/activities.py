memo = {}

def memo(f):
    
    def inner(cls, i, final):
        key = str(i)+str(final)
        if key not in memo:
            memo[key] = f(cls, i, final)
        return memo[key]
    return inner


@memo
def ans(cls, i, final):
    if(i == len(cls)):
        return 1
    else:
        hc = 0
        if cls[i][0] >= final:
            hc += ans(cls, i+1, cls[i][1])
        hc += ans(cls, i+1, final)
        return hc


while(True):
    cls = []
    memo = {}
    n = int(raw_input().strip())
    if n == -1:
        break
    for i in range(n):
        a, b = raw_input().strip().split()
        a = int(a)
        b = int(b)
        cls.append((a, b))
    cls.sort(key=lambda x: x[1])
    print "%08d" % ((ans(cls, 0, 0) - 1) % 100000000)
