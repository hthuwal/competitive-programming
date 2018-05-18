list=[]
list.append(0)
list.append(1)
for i in range (2,5000):
    list.append(list[i-1]+list[i-2])
t=int(raw_input())
while(t):
    n=int(raw_input())
    if n in list:
        print "YES"
    else:
        print "NO"
    t-=1
