from collections import Counter

s = input().strip()
hc = Counter(s)

for key in hc:
    hc[key] = hc[key] // 2

ans = ""

for i in range(len(s)):
    key = s[i]
    if hc[key] != 0:
        ans += key
        hc[key] -= 1

print(ans)

