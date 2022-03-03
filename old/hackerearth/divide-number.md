# Problem

https://www.hackerearth.com/practice/basic-programming/recursion/recursion-and-backtracking/practice-problems/algorithm/divide-number-a410603f/

# Brute/Recursive (TLE) :man_facepalming:

## Python(TLE)

```python
import time

def time_it(f):
    def inner(*args, **kwargs):
        start = time.time()
        ans = f(*args, **kwargs)
        end = time.time()
        print("Time Taken by " + f.__name__ + " is " + str(end-start) + " seconds.")
        return ans
    return inner

def get_factors(n):
    factors = []
    for i in range(1, n + 1):
        if n % i == 0:
            factors.append(i)
    return factors

@time_it
def solve_brute():
    num_fact = len(factors)
    ans = -1
    for a in factors:
        for b in factors:
            for c in factors:
                d = n - (a+b+c)
                if d in factors:
                    ans = max(ans, a*b*c*d)
    return ans


def solve_rec_util(n, k):
    # base case
    if n == 0 and k == 0:
        return 1

    if (n == 0 and k != 0) or (n != 0 and k == 0):
        return -1

    ans = -1
    for factor in factors:
        if factor <= n:
            subproblem = solve_rec_util(n - factor, k-1)
            if subproblem != -1:
                return subproblem * factor
    return ans

@time_it
def solve_rec(n):
    return solve_rec_util(n, 4)

t = int(input())

while(t>0):
    n = int(input())
    factors = get_factors(n)
    factors.sort(reverse=True)
    print(solve_rec(n))
    t -= 1
```

## C++

```cpp
#include <bits/stdc++.h>
#define vi vector<int>
#define lli long long int
using namespace std;

vi get_factors(int n)
{
    vi factors;
    for(int i=1;i<n;i++)
    {
        if(n%i==0)
            factors.push_back(i);
    }
    return factors;
}

lli solve_rec(int n, int k, vi &factors)
{
    if(n==0 and k==0) return 1;
    if((n==0 and k!=0) or (n!=0 and k==0)) return -1;

    lli ans = -1;

    for(int factor: factors)
    {
        if(factor <= n)
        {
            lli subproblem = solve_rec(n - factor, k - 1, factors);
            if (subproblem != -1)
                ans = max(ans, subproblem * factor);
        }
    } 
    return ans;
}

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        vi factors = get_factors(n);
        cout<<solve_rec(n, 4, factors)<<"\n";
    } 
}
```