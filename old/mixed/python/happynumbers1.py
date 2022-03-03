n=int(raw_input())
hc=[]
i=0
while(1):
    ans=0;
    i=i+1
    while(n!=0):
        temp=n%10
        ans=ans+temp**2
        n=n/10
    if(ans==1):
        print i
        break
    if ans in hc:
        print -1
        break
    else:
        hc.append(ans)
        n=ans
