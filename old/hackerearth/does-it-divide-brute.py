"""
Brute Force. Just to check the optimum solution
"""


def fact(n):
    ans = 1
    while(n > 0):
        ans *= n
        n -= 1
    return ans


def solve(n):
    jod = (n * (n + 1)) // 2
    if fact(n) % jod == 0:
        print("YES")
    else:
        print("NO")


if __name__ == '__main__':
    t = int(input())
    while t > 0:
        n = int(input())
        solve(n)
        t -= 1
