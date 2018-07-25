hc = {}
ch = {}
q = int(input().strip())
while q > 0:
    a, b = input().strip().split()
    a, b = int(a), int(b)
    if a == 1:
        if b not in hc:
            hc[b] = 1
            if 1 not in ch:
                ch[1] = 1
            else:
                ch[1] += 1
        else:
            ch[hc[b]] -= 1
            hc[b] += 1
            if hc[b] not in ch:
                ch[hc[b]] = 1
            else:
                ch[hc[b]] += 1

    elif a == 2:

        if b in hc and hc[b] != 0:
            ch[hc[b]] -= 1
            hc[b] -= 1
            if hc[b] not in ch:
                ch[hc[b]] = 1
            else:
                ch[hc[b]] += 1

    elif a == 3:

        if b in ch and ch[b] != 0:
            print(1)
        else:
            print(0)
    q -= 1
