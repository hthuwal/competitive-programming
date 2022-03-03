# https://www.spoj.com/problems/SPCQ/

t = int(input().strip())

while t > 0:
    n = int(input().strip())
    while True:
        dr = sum(map(int, list(str(n))))
        if n % dr == 0:
            print(n)
            break
        n += 1
    t -= 1
