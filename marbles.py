t=int(raw_input())
while(t):
    a,b=raw_input().split()
    a=int(a)-1
    b=int(b)-1
    nr=1
    dr=1
    for i in range(1,b+1):
        nr=nr*(a-i+1)
        dr=dr*i
    print nr/dr
    t-=1
