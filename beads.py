n = int(raw_input().strip())
while(n > 0):
    string = raw_input().strip()
    ans = 1
    hc = string
    for i in range(1, len(string)):
        cand = string[i:]+string[0:i]
        if(cand < hc):
            hc = cand
            ans = i+1
    print ans
    n -= 1
