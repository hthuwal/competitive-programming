t=int(raw_input())
while(t):
    hc=raw_input().split()
    if "machula" in hc[0]:
        print str(int(hc[4])-int(hc[2]))+" + "+hc[2]+" = "+hc[4]
    elif "machula" in hc[2]:
        print hc[0]+" + "+str(int(hc[4])-int(hc[0]))+" = "+hc[4]
    elif "machula" in hc[4]:
        print hc[0]+" + "+hc[2]+" = "+str(int(hc[0])+int(hc[2]))
    t-=1
