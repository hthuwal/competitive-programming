import sys
sys.stdin = open("in.txt","rb")
t=int(raw_input().strip())
while(t):
    n,k = map(int,raw_input().strip().split())
    x=[]
    count=0
    for i in range(0,n):
        x.append(map(int,raw_input().strip().split())[1:])
    for i in range(0,n):
        for j in range(i+1,n):
            if(len(set(x[i]+x[j]))==k):
                count=count+1
    print count
    t=t-1












