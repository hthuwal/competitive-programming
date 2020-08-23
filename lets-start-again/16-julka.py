# https://www.spoj.com/problems/JULKA/

for i in range(10):
    n = int(input().rstrip())
    b = int(input().rstrip())
    x = (n - b) // 2
    print(x + b)
    print(x)
    n -= 1
