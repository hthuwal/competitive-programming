'''
number of k dimensional hypercubes inside n dimensional
hypercube is nCk * 2^(n-k)

ans(n,k)  = number of k dimensional hyperubes of size 1 on the surface of 
k dimensional hypercube of size n

let N(j) denotes number of j dimesnional hypercubes in a k dimesnional hypercube

ans(n,k) = summation N(i)*(n^(i)-ans(n,i)) 
i from 0 to k-1

'''
import sys
import operator as op
sys.stdin = open("in.txt", "r")

memoi = {}


def C(n, k):
    k = k if k <= n-k else n-k
    if(k == 0):
        return 1
    nr = reduce(op.mul, [n-i for i in range(0, k)])
    dr = reduce(op.mul, [i for i in range(1, k+1)])
    return nr/dr


def cubes_on_surface(n, d):
    if (d, n) in memoi:
        return memoi[(d, n)]

    if d == 0:
        memoi[(d, n)] = 0
        return 0
    
    if d == 1:
        memoi[(d, n)] = 2
        return memoi[(d, n)]

    if d == 2:
        memoi[(d, n)] = 4*(n-1)
        return memoi[(d, n)]

    ans = 0
    for k in range(d-1, -1, -1):
        # nkd = number of k dimensional cube inside d dimensional cube
        nkd = C(d, k) * (2**(d-k))
        cur = (nkd * ((n**(k))-cubes_on_surface(n,k)))
        ans += cur
    
    memoi[(d, n)] = ans
    return ans

t = int(raw_input().strip())
while t > 0:
    s, d = map(int, raw_input().strip().split())  # s is size, d is dimension
    print cubes_on_surface(s, d)
    t = t - 1 

