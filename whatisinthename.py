import sys
sys.stdin = open("in.txt","rb")
t=int(raw_input())
while(t!=0):
    a=raw_input().strip().title().split()
    if(len(a)>=2):
        a[0]=a[0][0]+"."
    if(len(a)==3):
        a[1]=a[1][0]+"."
    print ' '.join(a)
    t=t-1
