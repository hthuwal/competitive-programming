# https://www.spoj.com/problems/BANDW/
# 
# Convert
# BBNBBNBBBB --to--> NNNNNBBNNB
# in minimum number of moves. In one move we can flip
# any number of contiguous characters

# ans is the number of opposite segments

while True:
    source, target = input().strip().split()
    if source == "*":
        break
    else:
        ans = 0
        last_same = True
        for a, b in zip(source, target):
            if a != b:
                last_same = False
                continue

            if a == b and last_same is False:
                ans += 1
                last_same = True
        if last_same is False:
            ans += 1
        print(ans)
