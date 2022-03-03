t=int(raw_input())
while(t):
    hc=raw_input()
    count=0
    for i in range(4,len(hc)-4):
        if (hc[i]=='a'or hc[i]=='e' or hc[i]=='i' or hc[i]=='o'or hc[i]=='u'):
            count+=1
    print str(4+count)+'/'+str(len(hc))
    t=t-1
