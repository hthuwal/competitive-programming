t=int(raw_input())
while(t):
    hc=[]
    n=int(raw_input())
    for i in range(0,n):
        hc.append(raw_input())
    hc.sort()
    a=""
    count=0
    for element in hc:
        if(element != a):
            print element+" "+str(hc.count(element))
            a=element
    print
    if(t!=1):
        temp=raw_input()
    t-=1
