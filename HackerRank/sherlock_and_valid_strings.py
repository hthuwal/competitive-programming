from collections import Counter

inp = input()
hc_hash = {}

for i in inp:
    if i not in hc_hash:
        hc_hash[i] = 0
    hc_hash[i] += 1
print(hc_hash)
values = Counter(hc_hash.values())
print(values)
if len(values) > 2:
    print("NO")
elif len(values) == 2:
    a, b = values.keys()
    t = (values[a] == 1 or values[b] == 1)
    x = (abs(a - b) == 1 and t)
    y = (a == 1 and values[a] == 1)
    z = (b == 1 and values[b] == 1)

    if x or y or z:
        print("YES")
    else:
        print("NO")
else:
    print("YES")
