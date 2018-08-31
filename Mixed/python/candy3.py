t=int(raw_input())
while(t):
    x=raw_input()
    n=int(raw_input())
    ans=0;
    for i in range(0,n):
        temp=int(raw_input())
        ans=ans+temp;
    if(ans%n==0):
        print 'YES'
    else:
        print 'NO'
    t-=1
