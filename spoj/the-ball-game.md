## Problem

[The Ball Game](https://www.spoj.com/problems/IEEEBGAM/)

The game is played with N white balls, N black balls and N boxes. A person chooses one box randomly and one ball from it randomly. Arrange the balls in boxes in such a way that the probability of getting a white ball is maximized.

## Solution

| Box 1 | Box 2 | Box 3 | Box 4 | ........ | Box n|
|:-----:|:-----:|:-----:|:-----:|:--------:|:----:|
| 1 W   |  1 W  |  1 W  |  1 W  | ........ | 1 W, N B |

```
Probability of getting a white ball 
    = (1/N) *  [ 1 + 1 + 1 + ..... + (1/(N+1)) ]
    = (1/N) *  [ (N - 1) * (N + 1) + 1 ] / (N + 1)
    = (1/N) *  [ N^2 ] / (N + 1)
    = N / N + 1  
```

:smiley:

### Python Code (gives NZEC idk why)
```python
def ans(n):
    prob = (n / (n+1))
    return round(prob, 8)

t = int(input().strip())
for i in range(t):
    n = int(input().strip())
    print("%0.8f" % ans(n))
```

### C++ code (Got Expected)

```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d", &n);
        double ans = n * 1.0 * (n+1);
        printf("%0.8lf\n", ans);
    }
}
```