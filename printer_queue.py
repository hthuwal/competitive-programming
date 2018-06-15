t = int(input().strip())

while t > 0:
    d = {x: 0 for x in range(10)}
    n, m = input().strip().split()
    n, m = int(n), int(m)
    p = list(map(int, input().strip().split()))
    p = [(i, int(p[i])) for i in range(len(p))]

    for each in p:
        d[each[1]] += 1

    time = 0
    while True:
        # print(p, time)
        front = p.pop(0)
        bada = False
        for i in range(front[1] + 1, 10):
            if d[i] > 0:
                bada = True
                break

        if bada:
            p.append(front)
        else:
            time += 1
            d[front[1]] -= 1
            if front[0] == m:
                print(time)
                break
    t -= 1
