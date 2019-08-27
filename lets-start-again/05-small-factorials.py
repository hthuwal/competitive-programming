# https://www.spoj.com/problems/FCTRL/

fact = {}


def calculate(n):
    if n not in fact:
        if n == 1:
            fact[n] = 1
        else:
            fact[n] = n * calculate(n - 1)
    return fact[n]


t = int(input())

while(t > 0):
    n = int(input())
    print(calculate(n))
    t -= 1
