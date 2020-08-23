import sys
sys.stdin = open("in.txt","rb")

from random import randint
def exp(a,b,m):
    ans=1
    a=a%m
    while(b>0):
        if(b&1):
            ans=(ans*a)%m
        b=b>>1##b/=2
        a=(a*a)%m
    return ans

def isPrimeUsingFermat(p,iter):
    if p==1:
        return False
    else:
        for i in range(0,iter):
            a = randint(0,p-2)+1
            if(exp(a,p-1,p)!=1):
                return False
        return True
        
t = int(raw_input())
while(t):
    x=int(raw_input())
    if(isPrimeUsingFermat(x,20)):
        print "YES"
    else:
        print "NO"
    t=t-1