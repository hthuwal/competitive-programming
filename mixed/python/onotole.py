n=int(raw_input())
hc=[];
while(n):
    x=int(raw_input())
    if x not in hc:
        hc.append(x)
    else:
        hc.remove(x)
    n=n-1
print hc[0]
