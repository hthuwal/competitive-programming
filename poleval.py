import sys
sys.stdin = open("in.txt","r")
def evaluate(c,x,n):
    ans=c[0]
    for i in range(n):
        ans = ans*x + c[i+1]
    return ans
count=0

while(True):
    n=int(raw_input().strip())
    if(n==-1):
        break
    count+=1
    print("Case %d:" % (count))
    c = map(int,raw_input().strip().split())
    k = int(raw_input().strip())
    x = map(int,raw_input().strip().split())
    for _ in x:
        print evaluate(c,_,n)
        
