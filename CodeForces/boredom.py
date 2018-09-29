"""
https://codeforces.com/problemset/problem/455/A
"""

from collections import Counter
n = int(input().strip())
a = list(map(int, input().strip().split()))
a = Counter(a)
a = list(a.items())
a.sort(key=lambda x: x[0])


dp = [0] * len(a)

dp[0] = a[0][0] * a[0][1]

for i in range(1, len(dp)):
    a1 = 0
    a2 = 0

    #  I choose current element
    if(a[i][0] - 1 == a[i - 1][0]):
        if (i == 1):
            a1 = a[i][0] * a[i][1]
        else:
            a1 = dp[i - 2] + a[i][0] * a[i][1]
    else:
        a1 = dp[i - 1] + a[i][0] * a[i][1]

    # Or I don't
    a2 = dp[i - 1]

    dp[i] = max(a1, a2)

print(dp[len(dp) - 1])
