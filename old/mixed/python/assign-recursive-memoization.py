import sys 
sys.stdin = open("in.txt","rb")

mymap={}

def hc(a,x,n,hash):
    key = str(x)+str(n)+"".join(map(str,hash))
    # print key
    if(x>=n):
        return 1
    elif(key  in mymap):
        return mymap[key]
    else:
        ans=0
        for i in range(0,n):
            if(hash[i]==0 and a[x][i]==1):
                hash[i]=1
                ans=ans+hc(a,x+1,n,hash)
                hash[i]=0
        mymap[key]=ans
        return ans

c = int(raw_input())
while(c>0):
    a=[]
    mymap.clear()
    n = int(raw_input())
    for i in range(0,n):
        a.append(map(int,raw_input().strip().split()))
    hash = [0]*25
    print hc(a,0,n,hash)
    c=c-1
