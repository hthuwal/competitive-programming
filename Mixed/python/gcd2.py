t=int(raw_input())
def gcd(a,b):
    if(b==0):
        return a
    else:
        return gcd(b,a%b)
while(t):
    a,b=raw_input().split()
    a=int(a)
    b=int(b)
    print gcd(a,b)
    t=t-1
