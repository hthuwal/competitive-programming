n, k = input().strip().split()
n, k = int(n), int(k)

imp = []
unimp = []
for i in range(n):
    a, b = input().strip().split()
    a, b = int(a), int(b)
    imp.append(a) if b == 1 else unimp.append(a)


need_to_win = 0 if k > len(imp) else (len(imp) - k)

imp.sort()
print(sum(imp[need_to_win:]) + sum(unimp) - sum(imp[0:need_to_win]))
